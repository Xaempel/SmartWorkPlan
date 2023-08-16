#include "../include/models/shiftdatamodel.hpp"

void ShiftDataModel::saveShift(QString nameSurNameStr, int DateofShift)
{
   if (!dataFile.open(QIODevice::ReadWrite)) {
      qWarning() << "Cannot open data.json for reading and writing.";
   }

   QByteArray jsonData {dataFile.readAll()};
   QJsonDocument jsonDocument {QJsonDocument::fromJson(jsonData)};
   QJsonObject jsonObj {jsonDocument.object()};

   QJsonArray ShiftArray = jsonObj["Shift"].toArray();

   QJsonObject shiftObject;
   shiftObject["nameSurName"] = nameSurNameStr;
   shiftObject["DateofShift"] = DateofShift;

   ShiftArray.append(shiftObject);

   jsonObj["Shift"] = ShiftArray;

   dataFile.resize(0);
   dataFile.seek(0);
   dataFile.write(QJsonDocument(jsonObj).toJson());
   dataFile.close();
}

QVector<QPair<QString, int>> ShiftDataModel::loadShift()
{
   QVector<QPair<QString, int>> shiftDataVec;

   if (!dataFile.open(QIODevice::ReadWrite)) {
      qWarning() << "Cannot open data.json for reading.";
      return shiftDataVec;
   }

   QByteArray jsonData {dataFile.readAll()};
   QJsonDocument jsonDocument {QJsonDocument::fromJson(jsonData)};
   QJsonObject jsonObj {jsonDocument.object()};

   QJsonArray ShiftArray = jsonObj["Shift"].toArray();

   for (const auto& item : ShiftArray) {
      if (item.isObject()) {
         QJsonObject shiftObject = item.toObject();
         if (shiftObject.contains("nameSurName") && shiftObject.contains("DateofShift")) {
            QString nameSurName = shiftObject["nameSurName"].toString();
            int dateOfShift     = shiftObject["DateofShift"].toInt();
            shiftDataVec.append(qMakePair(nameSurName, dateOfShift));
         }
      }
   }

   dataFile.close();
   return shiftDataVec;
}

void ShiftDataModel::removeShiftFromLists(int shiftNumberToDeleted)
{
   if (!dataFile.open(QIODevice::ReadWrite)) {
      qWarning() << "Cannot open data.json for reading and writing.";
      return;
   }

   QByteArray jsonData {dataFile.readAll()};
   QJsonDocument jsonDocument {QJsonDocument::fromJson(jsonData)};
   QJsonObject jsonObj {jsonDocument.object()};

   QJsonArray ShiftArray = jsonObj["Shift"].toArray();

   ShiftArray.removeAt(shiftNumberToDeleted);

   jsonObj["Shift"] = ShiftArray;

   dataFile.resize(0);
   dataFile.seek(0);
   dataFile.write(QJsonDocument(jsonObj).toJson());
   dataFile.close();
}