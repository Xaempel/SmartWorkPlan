#include "../include/depmanagerhelpers/dependencyworkermanager.hpp"

DependencyWorkerManager::DependencyWorkerManager(QVBoxLayout* workerLayout)
    : workerLayoutPtr(workerLayout)
{
   WorkerController::runLoadWorker(workerLayout);
}

void DependencyWorkerManager::callAddWorker() { workerController.runAddWorker(workerLayoutPtr); }
void DependencyWorkerManager::callDeleteWorker() { workerController.runDeleteWorker(); }