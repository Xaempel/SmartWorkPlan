-- DataModel: The Docs was created in version 0.7.1 

--- Inherits: Does not inherit

--- Class goals: this class is responsible for data management

---- public Methods:

1. bool save(std::optional<QString> nameFiletosave, QString dataSectionName, DataPack... dataPack): 
        
    this function have a responsible for saving data to file

2. void load(const QString fileName, const QString dataSectionName, QVariantList& vectorforLoadData):

    this function get data from file and emplace data to QVariantList 

3. void deleteDatafromFile(QString fileName, QString dataSectionName, int indexOfData)

    this function removes data from the file based on index

---- helper functions from the datamodel.hpp file

namespace: HelpfulDatamodelThing
1. QList<T> convertVariantToRequiredType(const QVariantList& listsForConversion)
    this function help convert QVariantList to list in given type T

[Home](../../ReadMe.md)