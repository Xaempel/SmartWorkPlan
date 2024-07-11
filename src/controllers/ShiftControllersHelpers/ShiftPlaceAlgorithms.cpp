#include "include/controllers/ShiftControllersHelpers/ShiftPlaceAlgorithms.hpp"

#include "include/models/DataModel.hpp"

#include <QString>
#include <QVBoxLayout>
#include <random>

const QString workerShiftsSaveFile {"WorkersShifts.json"};
const QString workerDataSectionName {"worker section"};

void ShiftPlaceAlgorithms::singlePlaceShiftAlgorithms(ShiftWizard* shiftWizard, ShiftModel* shiftModel, QVector<CalendarFieldWidget*>* calendarFieldWidgets)
{
   QVBoxLayout* workerShiftLayoutPtr {nullptr};
   QString workerNameSurName {""};
   int dayNumber {0};

   DataModel dataModel;

   shiftWizard->getDataFromWizard(workerNameSurName, dayNumber);
   dayNumber--;

   auto shiftWidget = shiftModel->addShift(workerNameSurName);
   calendarFieldWidgets->at(dayNumber)->addShiftWidget(shiftWidget, workerNameSurName);

   dataModel.save(workerShiftsSaveFile, workerNameSurName, dayNumber);
}

void ShiftPlaceAlgorithms::autoPlaceShiftAlgorithms(ShiftModel* shiftModel, QVector<CalendarFieldWidget*>* calendarFieldWidgets)
{
   QVariantList list {};
   DataModel dataModel;

   dataModel.load("data.json", workerDataSectionName, list);
   QStringList listofWorker = ToolsforDataManipulation::convertVariantToRequiredType<QString>(list);

   const int daysofMonth {30};

   QString lastChoiceName {""};
   for (int i = 0; i < daysofMonth; i++) {
      std::mt19937 seedGenerator;
      std::uniform_int_distribution<int> distribution(1, listofWorker.size());
      seedGenerator.seed(std::random_device()());

      int seed = distribution(seedGenerator);

      if (seed >= listofWorker.size()) {
         seed = 0;
      }

      const int seedResetValue     = 0;
      const int alternateSeedValue = 1;

      // Checking whether the current employee on the list (indexed by 'seed') is the same as
      // the previous 'lastChoiceName' and, if necessary, changing the seed index values, this is to avoid duplicate employees
      if (listofWorker.at(seed) == lastChoiceName) {
         if (seed == seedResetValue) {
            seed = alternateSeedValue;
         }
         else {
            seed = seedResetValue;
         }
      }

      QVBoxLayout* workerLayoutPtr {new QVBoxLayout};
      auto shiftWidget = shiftModel->addShift(listofWorker.at(seed));
      calendarFieldWidgets->at(i)->addShiftWidget(shiftWidget, listofWorker.at(seed));
      lastChoiceName = listofWorker.at(seed);

      dataModel.save(workerShiftsSaveFile, listofWorker.at(seed), i);
      seed++;
   }
}