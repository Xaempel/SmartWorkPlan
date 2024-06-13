#include "../include/depmanagerhelpers/dependencyshiftmanager.hpp"

DependencyShiftManager::DependencyShiftManager(QVBoxLayout* calendarLayout, InterFace::IShiftModel* ishiftModel)
    : ishiftModelPtr(ishiftModel)
{
   shiftDataController = std::make_unique<ShiftDataController>(ishiftModelPtr, dataModel.get(), &calendarFieldWidgets);
   shiftController     = std::make_unique<ShiftController>(ishiftModelPtr, dataModel.get(), &calendarFieldWidgets);
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
}

void DependencyShiftManager::handleDeleteWorker(QString nameofDeletedWorker)
{
   for (auto i : calendarFieldWidgets) {
      for (auto j : i->getShiftDataList()) {
         if (j.second == nameofDeletedWorker) {
            j.first->deleteLater();
         }
      }
   }
   dataModel->deleteSection("WorkersShifts.json", nameofDeletedWorker);
}

void DependencyShiftManager::refreshPointer()
{
   dataModel           = nullptr;
   shiftController     = nullptr;
   shiftDataController = nullptr;
   dataModel           = std::make_unique<DataModel>();
   shiftDataController = std::make_unique<ShiftDataController>(ishiftModelPtr, dataModel.get(), &calendarFieldWidgets);
   shiftController     = std::make_unique<ShiftController>(ishiftModelPtr, dataModel.get(), &calendarFieldWidgets);
}