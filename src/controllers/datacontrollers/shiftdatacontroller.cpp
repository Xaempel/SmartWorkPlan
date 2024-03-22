#include "../include/controllers/datacontrollers/shiftdatacontroller.hpp"

using namespace DataControllers;

const QString workerDataSectionName {"worker section"};

const QString shiftDataSectionName {"shift section name"};
const QString shiftDataSectionDate {"shift section date"};

ShiftDataController::ShiftDataController(IShiftModel* shiftModel, DataModel* dataModel, QVector<CalendarFieldWidget*>* calendarFieldWidgetVec)
    : shiftModelPtr(shiftModel)
    , dataModelPtr(dataModel)
    , calendarFieldWidgetVecPtr(calendarFieldWidgetVec)
{
}

void ShiftDataController::setCalendarWidgetinLayout(QVBoxLayout* LayoutPtr)
{
   CalendarWidget* calendarWidget {new CalendarWidget(nullptr)};

   int DayCounter {1};
   for (int i = 0; i < 30; i++) {
      calendarFieldWidgetVecPtr->emplace_back(new CalendarFieldWidget(nullptr, DayCounter));
      calendarFieldWidgetVecPtr->at(i)->setFixedSize(160, 160);

      calendarWidget->addWidgettoCalendar(calendarFieldWidgetVecPtr->at(i),i);
      DayCounter++;
   }

   LayoutPtr->addWidget(calendarWidget);
}

void ShiftDataController::runLoadShift(QVBoxLayout* LayoutPtr)
{
   QVariantList dataList {};
   dataModelPtr->load("data.json", shiftDataSectionName, dataList);

   QStringList workerNameList {};
   workerNameList = ToolsforDataManipulation::convertVariantToRequiredType<QString>(dataList);

   dataList.clear();
   dataModelPtr->load("data.json", shiftDataSectionDate, dataList);

   QList<int> dayList {};
   dayList = ToolsforDataManipulation::convertVariantToRequiredType<int>(dataList);

   QVBoxLayout* workerShiftLayoutPtr;

   for (int i = 0; i < dataList.size(); i++) {
      QString currentWorkerShiftName = workerNameList.at(i);
      int currentShiftDate           = dayList.at(i);

      calendarFieldWidgetVecPtr->at(currentShiftDate)->getPointertoWorkerShiftPlace(workerShiftLayoutPtr);
      shiftModelPtr->addShift(workerShiftLayoutPtr, currentWorkerShiftName);
   }
}