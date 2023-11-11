#include "./include/models/workermodel.hpp"

WorkerModel::WorkerModel(QList<QWidget*>* workerWidgetList)
    : workerWidgetListPtr(workerWidgetList)
{
}

void WorkerModel::addWorker(QVBoxLayout* LayoutToAddWorker, QWidget* WidgetoLayout)
{
   workerWidgetListPtr->emplace_back(WidgetoLayout);
   auto CurrentListsObject {workerWidgetListPtr->at(workerWidgetListPtr->size() - 1)};

   CurrentListsObject->setFixedSize(200, 100);
   LayoutToAddWorker->addWidget(CurrentListsObject);
}

void WorkerModel::deleteWorker(int NumberWorkerToRemoved)
{
   workerWidgetListPtr->at(NumberWorkerToRemoved)->deleteLater();
   workerWidgetListPtr->removeAt(NumberWorkerToRemoved);
}