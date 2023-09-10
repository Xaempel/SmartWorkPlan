#include "../include/depmanagerhelpers/dependencyworkermanager.hpp"

DependencyWorkerManager::DependencyWorkerManager(QVBoxLayout* workerLayout)
    : workerLayoutPtr(workerLayout)
{
   workerController->runLoadWorker(workerLayout);
}

void DependencyWorkerManager::callAddWorker() { workerController->runAddWorker(workerLayoutPtr); }

void DependencyWorkerManager::callDeleteWorker()
{
   workerController->runDeleteWorker();
   emittedWorkerDeleted(workerController->getDeletedWorkerName());
}