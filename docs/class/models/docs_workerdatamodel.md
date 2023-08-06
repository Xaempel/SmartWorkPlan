# Worker Data Model 
[Home](../../ReadMe.md) 
 
The Worker Data Model class is responsible for the data of Worker

## Inheritance
  
this class does not inherit 

## Class headers

    QByteArray
    QFile
    QJsonArray
    QJsonDocument
    QJsonObject
    QStringList

## Class methods 

### bool saveWorkerLists(QString Name, QString SurName);

this methods save a worker and returns true is this operation is success

### QStringList loadWorkerLists();

this methods return a Worker Name and Sur Name Lists

### void removeWorkerFromLists(int workerNumberToDeleted);

this method removes the worker based on the passed integer 