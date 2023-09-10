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

void DependencyShiftManager::handleWorkerDeleted(QString workerName)
{
   refreshPointer();
   QVariantList shiftDataList {};
   dataModel->load("data.json", "shift section name", shiftDataList);

   for (int i = shiftDataList.size() - 1; i >= 0; --i) {
      if (shiftDataList.at(i).toString() == workerName) {
         shiftModel->deleteShift(i);

         dataModel->deleteDatafromFile("data.json", "shift section name", i);
         dataModel->deleteDatafromFile("data.json", "shift section date", i);
      }
   }
}

void DependencyShiftManager::refreshPointer()
{
   dataModel       = nullptr;
   shiftController = nullptr;
   dataModel       = std::make_unique<DataModel>();
   shiftController = std::make_unique<ShiftController>(shiftModel.get(), dataModel.get());
}

QVector<QLabel*> DependencyShiftManager::workerWidgetVec {};