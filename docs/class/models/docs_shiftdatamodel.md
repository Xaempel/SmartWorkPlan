# Shift Data Model 
[Home](../../ReadMe.md) 
 
The Shift Data Model class is responsible for the data of shift

## Inheritance
  
this class does not inherit 

## Class headers

    QByteArray
    QFile
    QJsonArray
    QJsonDocument
    QJsonObject
    QPair
    QVector

## Class methods 

### void saveShift(QString nameSurNameStr, int DateofShift);

this methods save a Worker Name and Surname and data for shift in file

### QVector<QPair<QString, int>> loadShift(); 

this method returns worker shift data I recommend to use auto type to retrieve data for this method due to quite ugly type 