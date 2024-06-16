#include "include/controllers/PrintController.hpp"

void PrintController::runStartPrint()
{
   PrintModel printModel;

   QVariantList dataList;
   DataModel dataModel;
   dataModel.load("data.json", "worker section", dataList);

   QStringList workerNameList;
   workerNameList = ToolsforDataManipulation::convertVariantToRequiredType<QString>(dataList);

   using workerName = QString;
   using shiftsList = QStringList;
   using ShiftsList = QList<QPair<shiftsList, workerName>*>;

   ShiftsList shifts;
   int loopCounter {0};

   QStringList shiftsStr;
   for (auto i : workerNameList) {
      dataModel.load("WorkersShifts.json", i, dataList);
      shiftsStr = ToolsforDataManipulation::convertVariantToRequiredType<QString>(dataList);
      shifts.append(new QPair(shiftsStr, i));
   }

   printModel.startPrint(workerNameList, shifts);
}