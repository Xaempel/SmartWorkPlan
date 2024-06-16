#include "include/models/ShiftModel.hpp"

QLabel* ShiftModel::addShift(QString workerName)
{
   QLabel* newShiftWidget {new QLabel};

   newShiftWidget->setText(workerName);

   return newShiftWidget;
}
