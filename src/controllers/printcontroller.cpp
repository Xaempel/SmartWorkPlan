#include "../include/controllers/printcontroller.hpp"

void PrintController::runStartPrint(){
    PrintModel printModel;
    WorkerDataModel workerDataModel; 
    printModel.startPrint(workerDataModel.loadWorkerLists());
}