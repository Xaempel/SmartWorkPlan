#include "../include/depmanagerhelpers/dependencyshiftmanager.hpp"

DependencyShiftManager::DependencyShiftManager(QVBoxLayout* calendarLayout, InterFace::IShiftModel* ishiftModel, QVector<CalendarFieldWidget*>* calendarFieldWidgetVec)
    : ishiftModelPtr(ishiftModel)
    , calendarFieldWidgetVecPtr(calendarFieldWidgetVec)
{
   shiftDataController = std::make_unique<ShiftDataController>(ishiftModelPtr, dataModel.get(), calendarFieldWidgetVecPtr);
   shiftController     = std::make_unique<ShiftController>(ishiftModelPtr, dataModel.get(), calendarFieldWidgetVecPtr);
   shiftDataController->setCalendarWidgetinLayout(calendarLayout);
   shiftDataController->runLoadShift(calendarLayout);
}

void DependencyShiftManager::callAddShift()
{
   shiftController->runAddShift();
   refreshPointer();
}

void DependencyShiftManager::callDeleteShift()
{
   shiftController->runDeleteShift();
   refreshPointer();
}

void DependencyShiftManager::handleWorkerDeleted(QString workerName)
{
   refreshPointer();
   QVariantList shiftDataList {};
   dataModel->load("data.json", "shift section name", shiftDataList);

   for (int i = shiftDataList.size() - 1; i >= 0; --i) {
      if (shiftDataList.at(i).toString() == workerName) {
         ishiftModelPtr->deleteShift(i);

         dataModel->deleteDatafromFile("data.json", "shift section name", i);
         dataModel->deleteDatafromFile("data.json", "shift section date", i);
      }
   }
}

void DependencyShiftManager::refreshPointer()
{
   dataModel           = nullptr;
   shiftController     = nullptr;
   shiftDataController = nullptr;
   dataModel           = std::make_unique<DataModel>();
   shiftDataController = std::make_unique<ShiftDataController>(ishiftModelPtr, dataModel.get(), calendarFieldWidgetVecPtr);
   shiftController     = std::make_unique<ShiftController>(ishiftModelPtr, dataModel.get(), calendarFieldWidgetVecPtr);
}