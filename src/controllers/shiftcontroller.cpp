#include "../include/controllers/shiftcontroller.hpp"

const QString workerDataSectionName {"worker section"};

const QString shiftDataSectionName {"shift section name"};
const QString shiftDataSectionDate {"shift section date"};

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

   QVector<QString> workerNameVec {};
   QVector<int> shiftDateVec {};
   QVector<QPair<QString, int>> shiftVector;

   dataModelPtr->load("data.json", shiftDataSectionName, dataList);
   for (const auto& i : dataList) {
      workerNameVec.append(i.toString());
   }

   dataList.clear();
   dataModelPtr->load("data.json", shiftDataSectionDate, dataList);

   for (const auto& i : dataList) {
      shiftDateVec.append(i.toInt());
   }

   short shiftLoopCounter {0};
   for (const auto& i : dataList) {
      shiftVector.append(QPair<QString, int>(workerNameVec.at(shiftLoopCounter), shiftDateVec.at(shiftLoopCounter)));
      shiftLoopCounter++;
   }

   ShiftRemovalDialog* shiftRemovalDialog {new ShiftRemovalDialog(nullptr, shiftVector)};
   int shiftIndex {0};

   int result = shiftRemovalDialog->exec();
   if (result == QDialog::Accepted) {
      shiftRemovalDialog->getDataFromWizard(shiftIndex);

      shiftModelPtr->deleteShift(shiftIndex);
      dataModelPtr->deleteDatafromFile("data.json", shiftDataSectionDate, shiftIndex);
      dataModelPtr->deleteDatafromFile("data.json", shiftDataSectionName, shiftIndex);
   }
   else {
      return;
   }
}

void ShiftController::addSinglePlaceShift(ShiftWizard* shiftWizard)
{
   QVBoxLayout* workerShiftLayoutPtr {nullptr};
   QString workerNameSurName {""};
   int dayNumber {0};

   shiftWizard->getDataFromWizard(workerNameSurName, dayNumber);
   dayNumber--;
   calendarFieldWidgetVecPtr->at(dayNumber)->getPointertoWorkerShiftPlace(workerShiftLayoutPtr);
   shiftModelPtr->addShift(workerShiftLayoutPtr, workerNameSurName);

   dataModelPtr->save(std::nullopt, shiftDataSectionName, workerNameSurName);
   dataModelPtr->save(std::nullopt, shiftDataSectionDate, dayNumber);
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

      calendarFieldWidgetVecPtr->at(i)->getPointertoWorkerShiftPlace(workerLayoutPtr);
      shiftModelPtr->addShift(workerLayoutPtr, listofWorker.at(seed));
      lastChoiceName = listofWorker.at(seed);

      dataModelPtr->save(std::nullopt, shiftDataSectionName, listofWorker.at(seed));
      dataModelPtr->save(std::nullopt, shiftDataSectionDate, i);
      seed++;
   }
}