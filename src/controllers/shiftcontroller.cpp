#include "../include/controllers/shiftcontroller.hpp"

const QString workerDataSectionName {"worker section"};

const QString shiftDataSectionName {"shift section name"};
const QString shiftDataSectionDate {"shift section date"};

ShiftController::ShiftController(IShiftModel* shiftModel, DataModel* dataModel)
    : shiftModelPtr(shiftModel)
    , dataModelPtr(dataModel)
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
   QVariantList dataList {};
   dataModelPtr->load("data.json", shiftDataSectionName, dataList);

   QStringList workerNameList {};
   workerNameList = HelpfulDatamodelThing::convertVariantToRequiredType<QString>(dataList);

   dataList.clear();
   dataModelPtr->load("data.json", shiftDataSectionDate, dataList);

   QList<int> dayList {};
   dayList = HelpfulDatamodelThing::convertVariantToRequiredType<int>(dataList);

   QVBoxLayout* workerShiftLayoutPtr;

   for (int i = 0; i < dataList.size(); i++) {
      QString currentWorkerShiftName = workerNameList.at(i);
      int currentShiftDate           = dayList.at(i);

      calendarFieldWidgetVec.at(currentShiftDate)->getPointertoWorkerShiftPlace(workerShiftLayoutPtr);
      shiftModelPtr->addShift(workerShiftLayoutPtr, currentWorkerShiftName);
   }
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
      QVBoxLayout* workerShiftLayoutPtr {nullptr};
      QString workerNameSurName {""};
      int dayNumber {0};

      shiftWizard->getDataFromWizard(workerNameSurName, dayNumber);
      dayNumber--;
      calendarFieldWidgetVec.at(dayNumber)->getPointertoWorkerShiftPlace(workerShiftLayoutPtr);
      workerShiftLayoutPtr_ = workerShiftLayoutPtr;
      shiftModelPtr->addShift(workerShiftLayoutPtr, workerNameSurName);

      dataModelPtr->save(std::nullopt, shiftDataSectionName, workerNameSurName);
      dataModelPtr->save(std::nullopt, shiftDataSectionDate, dayNumber);
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

QVector<CalendarFieldWidget*> ShiftController::calendarFieldWidgetVec {};