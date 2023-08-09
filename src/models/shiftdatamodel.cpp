#include "../include/models/shiftdatamodel.hpp"

void ShiftDataModel::saveShift(QString nameSurNameStr, int DateofShift)
{
   if (!dateFile.open(QIODevice::ReadWrite)) {
      qWarning() << "Cannot open data.json for reading and writing.";
   }

   QByteArray jsonData {dateFile.readAll()};
   QJsonDocument jsonDocument {QJsonDocument::fromJson(jsonData)};
   QJsonObject jsonObj {jsonDocument.object()};

   QJsonArray ShiftArray = jsonObj["Shift"].toArray();

   QJsonObject shiftObject;
   shiftObject["nameSurName"] = nameSurNameStr;
   shiftObject["DateofShift"] = DateofShift;

   ShiftArray.append(shiftObject);

   jsonObj["Shift"] = ShiftArray;

   dateFile.resize(0);
   dateFile.seek(0);
   dateFile.write(QJsonDocument(jsonObj).toJson());
   dateFile.close();
}

QVector<QPair<QString, int>> ShiftDataModel::loadShift()
{
   QVector<QPair<QString, int>> shiftDataVec;

   QFile dateFile("data.json");

   if (!dateFile.open(QIODevice::ReadWrite)) {
      qWarning() << "Cannot open data.json for reading.";
      return shiftDataVec;
   }

   QByteArray jsonData {dateFile.readAll()};
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

   dateFile.close();
   return shiftDataVec;
}