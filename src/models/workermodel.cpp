#include "./include/models/workermodel.hpp"

QList<WorkerWidget*> WorkerModel::WorkerWidgetList {};
int WorkerModel::WorkerNum {0};

void WorkerModel::addWorker(QVBoxLayout* LayoutToAddWorker, QString Name,
                            QString SurName)
{
   WorkerWidgetList.emplace_back(new WorkerWidget(nullptr, Name, SurName));
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