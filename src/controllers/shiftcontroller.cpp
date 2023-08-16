#include "../include/controllers/shiftcontroller.hpp"

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
   auto getShiftData = shiftDataModel.loadShift();
   QVBoxLayout* workerShiftLayoutPtr;

   for (int i = 0; i < getShiftData.size(); i++) {
      QString currentWorkerShiftName = getShiftData.at(i).first;
      int currentShiftDate           = getShiftData.at(i).second;

      calendarFieldWidgetVec.at(currentShiftDate)->getPointertoWorkerShiftPlace(workerShiftLayoutPtr);
      shiftModel->addShift(workerShiftLayoutPtr, currentWorkerShiftName);
   }
}

void ShiftController::runAddShift()
{
   QString workerNameSurName {""};
   int dayNumber {0};

   WorkerDataModel workerDataModel;
   ShiftWizard* shiftWizard {new ShiftWizard(nullptr, workerDataModel.loadWorkerLists())};

   int result = shiftWizard->exec();

   if (result == QDialog::Accepted) {
      QVBoxLayout* workerShiftLayoutPtr {nullptr};
      shiftWizard->getDataFromWizard(workerNameSurName, dayNumber);
      dayNumber--;
      calendarFieldWidgetVec.at(dayNumber)->getPointertoWorkerShiftPlace(workerShiftLayoutPtr);
      workerShiftLayoutPtr_ = workerShiftLayoutPtr;
      shiftModel->addShift(workerShiftLayoutPtr, workerNameSurName);
      shiftDataModel.saveShift(workerNameSurName, dayNumber);
   }
   else {
      return;
   }
}

void ShiftController::runDeleteShift()
{
   ShiftRemovalDialog* shiftRemovalDialog {new ShiftRemovalDialog(nullptr, shiftDataModel.loadShift())};
   int shiftIndex {0};

   int result = shiftRemovalDialog->exec();
   if (result == QDialog::Accepted) {
      shiftRemovalDialog->getDataFromWizard(shiftIndex);

      shiftModel->deleteShift(shiftIndex);
      shiftDataModel.removeShiftFromLists(shiftIndex);
   }
   else {
      return;
   }
}

QVector<CalendarFieldWidget*> ShiftController::calendarFieldWidgetVec {};
QVector<QLabel*> ShiftController::workerWidgetVec {};