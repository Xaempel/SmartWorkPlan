#include "./include/models/workermodel.hpp"

QList<QWidget*> WorkerModel::WorkerWidgetList {};
int WorkerModel::WorkerNum {0};

void WorkerModel::addWorker(QVBoxLayout* LayoutToAddWorker, QWidget* WidgetoLayout)
{
   WorkerWidgetList.emplace_back(WidgetoLayout);
   auto CurrentListsObject {WorkerWidgetList.at(WorkerNum)};

   CurrentListsObject->setFixedSize(200, 100);
   LayoutToAddWorker->addWidget(CurrentListsObject);
   WorkerNum++;
}

void WorkerModel::deleteWorker(int NumberWorkerToRemoved)
{
   WorkerWidgetList.at(NumberWorkerToRemoved)->deleteLater();
   WorkerWidgetList.removeAt(NumberWorkerToRemoved);
   WorkerNum--;
}