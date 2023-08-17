#include "../include/depmanagerhelpers/dependencyshiftmanager.hpp"

DependencyShiftManager::DependencyShiftManager(QVBoxLayout* calendarLayout)
{
   shiftController.setCalendarWidgetinLayout(calendarLayout);
   shiftController.runLoadShift(calendarLayout);
}

void DependencyShiftManager::callAddShift() { shiftController.runAddShift(); }

void DependencyShiftManager::callDeleteShift() { shiftController.runDeleteShift(); }