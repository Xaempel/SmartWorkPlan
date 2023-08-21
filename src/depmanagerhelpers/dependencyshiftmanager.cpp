#include "../include/depmanagerhelpers/dependencyshiftmanager.hpp"

DependencyShiftManager::DependencyShiftManager(QVBoxLayout* calendarLayout)
{
   shiftController->setCalendarWidgetinLayout(calendarLayout);
   shiftController->runLoadShift(calendarLayout);
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

void DependencyShiftManager::refreshPointer()
{
   shiftController = nullptr;
   workerDataModel = nullptr;
   shiftDataModel  = nullptr;
   shiftDataModel  = std::make_unique<ShiftDataModel>();
   workerDataModel = std::make_unique<WorkerDataModel>();
   shiftController = std::make_unique<ShiftController>(shiftDataModel.get(), workerDataModel.get(), shiftModel.get());
}

QVector<QLabel*> DependencyShiftManager::workerWidgetVec {};