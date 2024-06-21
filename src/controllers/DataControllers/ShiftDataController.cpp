#include "../include/controllers/DataControllers/ShiftDataController.hpp"

using namespace DataControllers;

const QString workerShiftsSaveFile {"WorkersShifts.json"};
const QString workerDataSectionName {"worker section"};

ShiftDataController::ShiftDataController(QVector<CalendarFieldWidget*>* calendarFieldWidgetVec)
    : calendarFieldWidgetVecPtr(calendarFieldWidgetVec)
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
   dataModel.load("data.json", workerDataSectionName, workerList);

   for (auto i : workerList) {
      QVariantList dataList;
      dataModel.load(workerShiftsSaveFile, i.toString(), dataList);

      // add widget to layout spaces
      QVBoxLayout* workerShiftLayoutPtr {nullptr};
      for (auto j : dataList) {
         auto shiftWidget = shiftModel.addShift(i.toString());
         calendarFieldWidgetVecPtr->at(j.toInt())->addShiftWidget(shiftWidget, i.toString());
      }
   }
}