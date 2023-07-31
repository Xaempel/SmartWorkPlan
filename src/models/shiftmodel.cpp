#include "../include/models/shiftmodel.hpp"

void ShiftModel::addShift(QVBoxLayout* PtrLayout, QString workerName)
{
   QLabel *workerLabel {new QLabel};
   workerLabel->setText(workerName);
   PtrLayout->addWidget(workerLabel);
}