#include "../include/models/shiftmodel.hpp"

ShiftModel::ShiftModel(QVector<QLabel*>& workerWidgetVector)
{
   workerWidgetVectorPtr = &workerWidgetVector;
}

void ShiftModel::addShift(QVBoxLayout* layouttoAddShift, QString workerName)
{
   workerWidgetVectorPtr->emplace_back(new QLabel);
   workerWidgetVectorPtr->at(workerWidgetNumber)->setText(workerName);
   layouttoAddShift->addWidget(workerWidgetVectorPtr->at(workerWidgetNumber));
   workerWidgetNumber++;
}

void ShiftModel::deleteShift(int shiftNumbertoDelete)
{
   workerWidgetVectorPtr->at(shiftNumbertoDelete)->deleteLater();
   workerWidgetVectorPtr->removeAt(shiftNumbertoDelete);
   workerWidgetNumber--;
}

int ShiftModel::workerWidgetNumber {0};