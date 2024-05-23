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

void DependencyShiftManager::refreshPointer()
{
   dataModel           = nullptr;
   shiftController     = nullptr;
   shiftDataController = nullptr;
   dataModel           = std::make_unique<DataModel>();
   shiftDataController = std::make_unique<ShiftDataController>(ishiftModelPtr, dataModel.get(), calendarFieldWidgetVecPtr);
   shiftController     = std::make_unique<ShiftController>(ishiftModelPtr, dataModel.get(), calendarFieldWidgetVecPtr);
}