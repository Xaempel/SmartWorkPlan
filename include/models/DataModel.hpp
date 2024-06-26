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

/// @brief This class is responsible for data management
class DataModel {
   public:
   /// @brief This function have a responsible for saving data to file
   /// @param nameFiletosave file to save data  
   /// @param ...dataPack data pack for save 
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

   /// @brief This function get data from file and emplace data to QVariantList  
   void load(const QString fileName, const QString dataSectionName, QVariantList& vectorforLoadData);
   
   /// @brief This function removes data from the file based on index
   void deleteDatafromFile(QString fileName, QString dataSectionName, int indexOfData);

   /// @brief This function removes shifts from file 
   /// @todo This function will be move in special file
   void deleteShiftsFromFile(QString dataSectionName,QString contentForDelete); 

   /// @brief a method delete section by section name variable
   void deleteSection(QString fileNametoDeleteSection,QString sectionName);

   private:
   std::unique_ptr<QFile> filetoSave {};
};

namespace ToolsforDataManipulation {

   /// @brief This function help convert QVariantList to list in given type T
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