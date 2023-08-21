#include "../include/controllers/shiftcontroller.hpp"

ShiftController::ShiftController(IShiftDataModel* shiftDataModel, IWorkerDataModel* workerDataModel, IShiftModel* shiftModel)
    : shiftDataModelPtr(shiftDataModel)
    , workerDataModelPtr(workerDataModel)
    , shiftModelPtr(shiftModel)
{
}

void ShiftController::setCalendarWidgetinLayout(QVBoxLayout* LayoutPtr)
{
   CalendarWidget* calendarWidget {new CalendarWidget(nullptr)};
   QGridLayout* calendarFieldWidgetPtr {nullptr};

   calendarWidget->getCalendarFieldWidgetLayoutPtr(calendarFieldWidgetPtr);

   int DayCounter {1};
   for (int i = 0; i < 30; i++) {
      calendarFieldWidgetVec.emplace_back(new CalendarFieldWidget(nullptr, DayCounter));
      calendarFieldWidgetVec.at(i)->setFixedSize(160, 160);

      calendarFieldWidgetPtr->addWidget(calendarFieldWidgetVec.at(i), i / 7, i % 7);
      DayCounter++;
   }

   LayoutPtr->addWidget(calendarWidget);
}

void ShiftController::runLoadShift(QVBoxLayout* LayoutPtr)
{
   auto getShiftData = shiftDataModelPtr->loadShift();
   QVBoxLayout* workerShiftLayoutPtr;

   for (int i = 0; i < getShiftData.size(); i++) {
      QString currentWorkerShiftName = getShiftData.at(i).first;
      int currentShiftDate           = getShiftData.at(i).second;

      calendarFieldWidgetVec.at(currentShiftDate)->getPointertoWorkerShiftPlace(workerShiftLayoutPtr);
      shiftModelPtr->addShift(workerShiftLayoutPtr, currentWorkerShiftName);
   }
}

void ShiftController::runAddShift()
{
   QString workerNameSurName {""};
   int dayNumber {0};

   ShiftWizard* shiftWizard {new ShiftWizard(nullptr, workerDataModelPtr->loadWorkerLists())};

   int result = shiftWizard->exec();

   if (result == QDialog::Accepted) {
      QVBoxLayout* workerShiftLayoutPtr {nullptr};
      shiftWizard->getDataFromWizard(workerNameSurName, dayNumber);
      dayNumber--;
      calendarFieldWidgetVec.at(dayNumber)->getPointertoWorkerShiftPlace(workerShiftLayoutPtr);
      workerShiftLayoutPtr_ = workerShiftLayoutPtr;
      shiftModelPtr->addShift(workerShiftLayoutPtr, workerNameSurName);
      shiftDataModelPtr->saveShift(workerNameSurName, dayNumber);
   }
   else {
      return;
   }
}

void ShiftController::runDeleteShift()
{
   ShiftRemovalDialog* shiftRemovalDialog {new ShiftRemovalDialog(nullptr, shiftDataModelPtr->loadShift())};
   int shiftIndex {0};

   int result = shiftRemovalDialog->exec();
   if (result == QDialog::Accepted) {
      shiftRemovalDialog->getDataFromWizard(shiftIndex);

      shiftModelPtr->deleteShift(shiftIndex);
      shiftDataModelPtr->removeShiftFromLists(shiftIndex);
   }
   else {
      return;
   }
}

QVector<CalendarFieldWidget*> ShiftController::calendarFieldWidgetVec {};