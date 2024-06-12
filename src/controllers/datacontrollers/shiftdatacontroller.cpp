#include "../include/controllers/datacontrollers/shiftdatacontroller.hpp"

using namespace DataControllers;

const QString workerShiftsSaveFile {"WorkersShifts.json"};
const QString workerDataSectionName {"worker section"};

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

      calendarWidget->addWidgettoCalendar(calendarFieldWidgetVecPtr->at(i), i);
      DayCounter++;
   }

   LayoutPtr->addWidget(calendarWidget);
}

void ShiftDataController::runLoadShift(QVBoxLayout* LayoutPtr)
{
   QVariantList workerList;
   dataModelPtr->load("data.json", workerDataSectionName, workerList);

   for (auto i : workerList) {
      QVariantList dataList;
      dataModelPtr->load(workerShiftsSaveFile, i.toString(), dataList);

      // add widget to layout spaces
      QVBoxLayout* workerShiftLayoutPtr {nullptr};
      for (auto j : dataList) {
         auto shiftWidget = shiftModelPtr->addShift(i.toString());
         calendarFieldWidgetVecPtr->at(j.toInt())->addShiftWidget(shiftWidget, i.toString());
      }
   }
}