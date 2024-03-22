#include "../include/models/datamodel.hpp"

void DataModel::load(const QString fileName, const QString dataSectionName, QVariantList& vectorforLoadData)
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

void DataModel::deleteDatafromFile(QString fileName, QString dataSectionName, int indexOfData)
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