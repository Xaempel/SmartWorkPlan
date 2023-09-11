/******************************************************************************
**                                                                            **
**  Copyright (C) [2023] [Xaempel]                                            **
**                                                                            **
**  This file is part of [SmartWorkPlan].                                     **
**  [SmartWorkPlan] is free software: you can redistribute it and/or          **
**  modify it under the terms of the GNU General Public License as published  **
**  by the Free Software Foundation, either version 2 of the License, or any  **
**  later version.                                                            **
**                                                                            **
**  [SmartWorkPlan] is distributed in the hope that it will be                **
**  useful, but WITHOUT ANY WARRANTY; without even the implied warranty of    **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             **
**  GNU General Public License for more details.                              **
**                                                                            **
**  You should have received a copy of the GNU General Public License along   **
**  with [SmartWorkPlan].  If not, see <https://www.gnu.org/licenses/>.       **
**                                                                            **
**  This project uses the Qt framework, which is licensed under the GNU       **
**  General Public License (GPL) version 2 or later. The full text of the     **
**  GPL license can be found in the LICENSE file.                             **
**                                                                            **
**  Qt is a cross-platform application framework maintained by The Qt Company.**
**  You can find more information about Qt and its licensing at               **
**  https://www.qt.io/.                                                       **
**                                                                            **
******************************************************************************/
#pragma once

#include <QByteArray>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <exception>
#include <memory>
#include <optional>
#include <type_traits>

class DataModel {
   public:
   template <typename... DataPack>
   bool save(std::optional<QString> nameFiletosave, QString dataSectionName, DataPack... dataPack)
   {
      if (!nameFiletosave.has_value()) {
         filetoSave = std::make_unique<QFile>("data.json");
      }
      else {
         filetoSave = std::make_unique<QFile>(nameFiletosave.value());
      }

      if (!filetoSave->open(QIODevice::ReadWrite | QIODevice::Text)) {
         return false;
      }

      QByteArray jsonData {filetoSave->readAll()};
      QJsonDocument jsonDocument {QJsonDocument::fromJson(jsonData)};
      QJsonObject jsonObject {jsonDocument.object()};
      QJsonArray array = jsonObject[dataSectionName].toArray();

      (array.append(dataPack), ...);

      jsonObject[dataSectionName] = array;
      jsonDocument.setObject(jsonObject);

      filetoSave->resize(0);
      filetoSave->seek(0);
      filetoSave->write(jsonDocument.toJson());
      filetoSave->close();
      return true;
   }

   void load(const QString fileName, const QString dataSectionName, QVariantList& vectorforLoadData)
   {
      try {
         filetoSave = std::make_unique<QFile>(fileName);
         if (!filetoSave->open(QIODevice::ReadWrite | QIODevice::Text)) {
            throw std::runtime_error("file " + fileName.toStdString() + " is not open");
         }

         QByteArray jsonData {filetoSave->readAll()};
         QJsonDocument jsonDocument {QJsonDocument::fromJson(jsonData)};
         QJsonObject jsonObject {jsonDocument.object()};
         QJsonArray array = jsonObject[dataSectionName].toArray();

         vectorforLoadData = array.toVariantList();

         filetoSave->resize(0);
         filetoSave->seek(0);
         filetoSave->write(jsonDocument.toJson());
         filetoSave->close();
      }
      catch (const std::exception& e) {
         qWarning() << "Something in the load method went wrong: " << e.what();
         return;
      }
   }

   void deleteDatafromFile(QString fileName, QString dataSectionName, int indexOfData)
   {
      try {
         if (!QFile::exists(fileName)) {
            throw std::runtime_error("there is no file with the given argument DataModel::deleteDatafromFile");
         }

         filetoSave = std::make_unique<QFile>(fileName);
         if (!filetoSave->open(QIODevice::ReadWrite | QIODevice::Text)) {
            throw std::runtime_error("file " + fileName.toStdString() + " is not open");
         }

         QByteArray jsonData {filetoSave->readAll()};
         QJsonDocument jsonDocument {QJsonDocument::fromJson(jsonData)};
         QJsonObject jsonObject {jsonDocument.object()};

         if (!jsonObject.contains(dataSectionName)) {
            throw std::runtime_error("the wrong section name was specified in the function deleteDatafromFile");
         }

         QJsonArray array = jsonObject[dataSectionName].toArray();

         if (indexOfData < 0 || indexOfData >= array.size()) {
            throw std::runtime_error("gived a data index too large or index < 0 in delete Data from File function");
         }

         array.removeAt(indexOfData);
         jsonObject[dataSectionName] = array;

         jsonDocument.setObject(jsonObject);

         filetoSave->resize(0);
         filetoSave->seek(0);
         filetoSave->write(jsonDocument.toJson());
         filetoSave->close();
      }
      catch (const std::exception& e) {
         qWarning() << "Something in the deleteDatafromFile method went wrong: " << e.what();
         return;
      }
   }

   private:
   std::unique_ptr<QFile> filetoSave {};
};

namespace HelpfulDatamodelThing {

   template <typename T>
   QList<T> convertVariantToRequiredType(const QVariantList& listsForConversion)
   {
      QList<T> listToReturn;

      for (const auto& item : listsForConversion) {
         if constexpr (std::is_same<T, int>::value) {
            listToReturn.append(item.toInt());
         }
         else if constexpr (std::is_same<T, QString>::value) {
            listToReturn.append(item.toString());
         }
         else {
            throw std::runtime_error("Unsupported type: supported types is QString and int ");
         }
      }

      return listToReturn;
   }

}