#include "../include/controllers/printcontroller.hpp"

void PrintController::runStartPrint()
{
   PrintModel printModel;

   QVariantList dataList;
   DataModel dataModel;
   dataModel.load("data.json", "worker section", dataList);

   QStringList workerNameList;
   workerNameList = HelpfulDatamodelThing::convertVariantToRequiredType<QString>(dataList);

   printModel.startPrint(workerNameList);
}