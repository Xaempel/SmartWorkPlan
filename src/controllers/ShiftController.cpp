#include "include/controllers/ShiftController.hpp"

#include "include/controllers/ShiftControllersHelpers/ShiftPlaceAlgorithms.hpp"
#include "include/widgets/RemovalDialogs/ShiftRemovalDialog.hpp"

const QString workerShiftsSaveFile {"WorkersShifts.json"};
const QString workerDataSectionName {"worker section"};

ShiftController::ShiftController(QVector<CalendarFieldWidget*>* calendarFieldWidgetVec)
    : calendarFieldWidgetVecPtr(calendarFieldWidgetVec)
{
}

void ShiftController::runAddShift()
{
   QVariantList dataList {};
   dataModel.load("data.json", workerDataSectionName, dataList);

   QStringList workerList {};

   int workerNameConvertLoopCounter {0};
   for (auto& i : dataList) {
      workerList.emplace_back(dataList.at(workerNameConvertLoopCounter).toString());
      workerNameConvertLoopCounter++;
   }

   ShiftWizard* shiftWizard {new ShiftWizard(nullptr, workerList)};
   int result = shiftWizard->exec();

   switch (result) {
      case QDialog::Accepted:
         if (shiftWizard->getAutoPlacementChoice() == false) {
            ShiftPlaceAlgorithms::singlePlaceShiftAlgorithms(shiftWizard, &shiftModel, calendarFieldWidgetVecPtr);
         }
         else {
            ShiftPlaceAlgorithms::autoPlaceShiftAlgorithms(&shiftModel, calendarFieldWidgetVecPtr);
         }
         break;
      case QDialog::Rejected:
         return;
   }
}

void ShiftController::runDeleteShift()
{
   QVariantList dataList {};
   dataModel.load("data.json", workerDataSectionName, dataList);

   QStringList workerName = ToolsforDataManipulation::convertVariantToRequiredType<QString>(dataList);

   QStringList shifts {};
   for (QString i : workerName) {
      dataModel.load(workerShiftsSaveFile, i, dataList);
      for (auto j : dataList) {
         shifts.append(j.toString() + " " + i);
      }
   }

   ShiftRemovalDialog removalDialog(nullptr, shifts);
   removalDialog.exec();

   auto selecedShiftData = removalDialog.getSelectedShiftsData();

   QString deletedWorkerName {selecedShiftData.second};
   int deletedWorkerDay {selecedShiftData.first};

   auto workerNameinCalendarWidget = calendarFieldWidgetVecPtr->at(deletedWorkerDay)->getShiftDataList();

   for (auto i : workerNameinCalendarWidget) {
      if (i.second == deletedWorkerName) {
         i.first->deleteLater();
         break;
      }
   }

   dataModel.load(workerShiftsSaveFile, deletedWorkerName, dataList);
   QStringList deletedWorkerShifts = ToolsforDataManipulation::convertVariantToRequiredType<QString>(dataList);

   int indexofDeletedDay {0};
   for (QString i : deletedWorkerShifts) {
      if (i.toInt() == deletedWorkerDay) {
         dataModel.deleteDatafromFile(workerShiftsSaveFile, deletedWorkerName, indexofDeletedDay);
      }
      indexofDeletedDay++;
   }
}