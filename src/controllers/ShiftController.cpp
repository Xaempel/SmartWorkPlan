#include "include/controllers/ShiftController.hpp"

#include "include/widgets/RemovalDialogs/ShiftRemovalDialog.hpp"

const QString workerShiftsSaveFile {"WorkersShifts.json"};

const QString workerDataSectionName {"worker section"};

ShiftController::ShiftController(IShiftModel* shiftModel, DataModel* dataModel, QVector<CalendarFieldWidget*>* calendarFieldWidgetVec)
    : shiftModelPtr(shiftModel)
    , dataModelPtr(dataModel)
    , calendarFieldWidgetVecPtr(calendarFieldWidgetVec)
{
}

void ShiftController::runAddShift()
{
   QVariantList dataList {};
   dataModelPtr->load("data.json", workerDataSectionName, dataList);

   QStringList workerList {};

   int workerNameConvertLoopCounter {0};
   for (auto& i : dataList) {
      workerList.emplace_back(dataList.at(workerNameConvertLoopCounter).toString());
      workerNameConvertLoopCounter++;
   }

   ShiftWizard* shiftWizard {new ShiftWizard(nullptr, workerList)};
   int result = shiftWizard->exec();

   if (result == QDialog::Accepted) {
      if (shiftWizard->getAutoPlacementChoice() == false) {
         addSinglePlaceShift(shiftWizard);
      }
      else {
         addAutomaticPlaceShift();
      }
   }
   else {
      return;
   }
}

void ShiftController::runDeleteShift()
{
   QVariantList dataList {};
   dataModelPtr->load("data.json", workerDataSectionName, dataList);

   QStringList workerName = ToolsforDataManipulation::convertVariantToRequiredType<QString>(dataList);

   QStringList shifts {};
   for (QString i : workerName) {
      dataModelPtr->load(workerShiftsSaveFile, i, dataList);
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

   dataModelPtr->load(workerShiftsSaveFile, deletedWorkerName, dataList);
   QStringList deletedWorkerShifts = ToolsforDataManipulation::convertVariantToRequiredType<QString>(dataList);

   int indexofDeletedDay {0};
   for (QString i : deletedWorkerShifts) {
      if (i.toInt() == deletedWorkerDay) {
         dataModelPtr->deleteDatafromFile(workerShiftsSaveFile, deletedWorkerName, indexofDeletedDay);
      }
      indexofDeletedDay++;
   }
}

void ShiftController::addSinglePlaceShift(ShiftWizard* shiftWizard)
{
   QVBoxLayout* workerShiftLayoutPtr {nullptr};
   QString workerNameSurName {""};
   int dayNumber {0};

   shiftWizard->getDataFromWizard(workerNameSurName, dayNumber);
   dayNumber--;

   auto shiftWidget = shiftModelPtr->addShift(workerNameSurName);
   calendarFieldWidgetVecPtr->at(dayNumber)->addShiftWidget(shiftWidget, workerNameSurName);

   dataModelPtr->save(workerShiftsSaveFile, workerNameSurName, dayNumber);
}

void ShiftController::addAutomaticPlaceShift()
{
   QVariantList list {};
   dataModelPtr->load("data.json", workerDataSectionName, list);
   QStringList listofWorker = ToolsforDataManipulation::convertVariantToRequiredType<QString>(list);

   const int daysofMonth {30};

   QString lastChoiceName {""};
   for (int i = 0; i < daysofMonth; i++) {
      std::mt19937 seedGenerator;
      std::uniform_int_distribution<int> distribution(1, listofWorker.size());
      seedGenerator.seed(std::random_device()());

      int seed = distribution(seedGenerator);

      if (seed >= listofWorker.size()) {
         seed = 0;
      }

      const int seedResetValue     = 0;
      const int alternateSeedValue = 1;

      // Checking whether the current employee on the list (indexed by 'seed') is the same as
      // the previous 'lastChoiceName' and, if necessary, changing the seed index values, this is to avoid duplicate employees
      if (listofWorker.at(seed) == lastChoiceName) {
         if (seed == seedResetValue) {
            seed = alternateSeedValue;
         }
         else {
            seed = seedResetValue;
         }
      }

      QVBoxLayout* workerLayoutPtr {new QVBoxLayout};
      auto shiftWidget = shiftModelPtr->addShift(listofWorker.at(seed));
      calendarFieldWidgetVecPtr->at(i)->addShiftWidget(shiftWidget, listofWorker.at(seed));
      lastChoiceName = listofWorker.at(seed);

      dataModelPtr->save(workerShiftsSaveFile, listofWorker.at(seed), i);
      seed++;
   }
}