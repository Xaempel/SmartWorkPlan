#include "./include/models/workerdatamodel.hpp"

bool WorkerDataModel::saveWorkerLists(QString Name, QString SurName)
{
   if (dataFile.open(QIODevice::ReadWrite)) {
      QByteArray jsonData {dataFile.readAll()};
      QJsonDocument jsonDocument {QJsonDocument::fromJson(jsonData)};
      QJsonObject jsonObject {jsonDocument.object()};

      QJsonArray NamesArray    = jsonObject["Names"].toArray();
      QJsonArray SurNamesArray = jsonObject["SurName"].toArray();

      NamesArray.append(Name);
      SurNamesArray.append(SurName);

      jsonObject["Names"]   = NamesArray;
      jsonObject["SurName"] = SurNamesArray;

      jsonDocument.setObject(jsonObject);

      dataFile.resize(0);
      dataFile.seek(0);
      dataFile.write(jsonDocument.toJson());
      dataFile.close();
      return true;
   }
   else {
      return false;
   }
}

QStringList WorkerDataModel::loadWorkerLists()
{
   if (!dataFile.open(QIODevice::ReadWrite)) {
      qWarning() << "Cannot open data.json for reading.";
      return nameSurnameList;
   }

   QByteArray jsonData {dataFile.readAll()};
   QJsonDocument jsonDocument {QJsonDocument::fromJson(jsonData)};
   QJsonObject jsonObject {jsonDocument.object()};

   QJsonArray namesArray    = jsonObject["Names"].toArray();
   QJsonArray surNamesArray = jsonObject["SurName"].toArray();

   dataFile.close();

   int WorkerNum {0};
   while (WorkerNum < namesArray.size()) {
      nameSurnameList.emplace_back(namesArray.at(WorkerNum).toString() + "  " + surNamesArray.at(WorkerNum).toString());
      WorkerNum++;
   }

   return nameSurnameList;
}

void WorkerDataModel::removeWorkerFromLists(int workerNumberToDeleted)
{
   if (dataFile.open(QIODeviceBase::ReadWrite)) {
      QByteArray jsonData {dataFile.readAll()};
      QJsonDocument jsonDocument {QJsonDocument::fromJson(jsonData)};
      QJsonObject jsonObject {jsonDocument.object()};

      QJsonArray namesArray    = jsonObject["Names"].toArray();
      QJsonArray surNamesArray = jsonObject["SurName"].toArray();

      if ( workerNumberToDeleted >= 0 &&  workerNumberToDeleted < nameSurnameList.size()) {
         namesArray.removeAt( workerNumberToDeleted);
         surNamesArray.removeAt( workerNumberToDeleted);
         nameSurnameList.removeAt( workerNumberToDeleted ); 
      }

      jsonObject["Names"]   = namesArray;
      jsonObject["SurName"] = surNamesArray;

      jsonDocument.setObject(jsonObject);

      dataFile.resize(0); 
      dataFile.write(jsonDocument.toJson());
   }
}