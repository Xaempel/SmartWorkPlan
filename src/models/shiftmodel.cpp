#include "../include/models/shiftmodel.hpp"

void ShiftModel::addShift(QVBoxLayout* layouttoAddShift, QString workerName)
{
   QLabel* newShiftWidget {new QLabel};

   newShiftWidget->setText(workerName);
   layouttoAddShift->addWidget(newShiftWidget);
}
