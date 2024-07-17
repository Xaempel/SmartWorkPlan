#include "../include/controllers/DataControllers/ShiftDataController.hpp"

using namespace DataControllers;

const QString workerShiftsSaveFile {"WorkersShifts.json"};
const QString workerDataSectionName {"worker section"};

ShiftDataController::ShiftDataController(QVector<CalendarFieldWidget*>* calendarFieldWidgetVec)
    : calendarFieldWidgetVecPtr(calendarFieldWidgetVec)
{
}

void ShiftDataController::setCalendarWidgetinLayout(QVBoxLayout* layouttoCalednarWidget)
{
   CalendarWidget* calendarWidget {new CalendarWidget(nullptr)};

   int DayCounter {1};
   for (int i = 0; i < 30; i++) {
      calendarFieldWidgetVecPtr->emplace_back(new CalendarFieldWidget(nullptr, DayCounter));
      calendarFieldWidgetVecPtr->at(i)->setFixedSize(160, 160);

      calendarWidget->addWidgettoCalendar(calendarFieldWidgetVecPtr->at(i), i);
      DayCounter++;
   }

   layouttoCalednarWidget->addWidget(calendarWidget);
}

void ShiftDataController::runLoadShift()
{
   QVariantList workerList;
   dataModel.load("data.json", workerDataSectionName, workerList);

   for (auto i : workerList) {
      QVariantList dataList;
      dataModel.load(workerShiftsSaveFile, i.toString(), dataList);

      for (auto j : dataList) {
         auto shiftWidget = shiftModel.addShift(i.toString());
         calendarFieldWidgetVecPtr->at(j.toInt())->addShiftWidget(shiftWidget, i.toString());
      }
   }
}