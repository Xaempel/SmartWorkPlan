#include "../include/controllers/workercontroller.hpp"

void WorkerController::runAddWorker(QVBoxLayout* workerLayoutPtr)
{
   QString WorkerName {""};
   QString WorkerSurName {""};

   WorkerWizard* WorkerWizardObj {new WorkerWizard};
   WorkerWizardObj->exec();

   WorkerDataModel DataModelObject {};
   if (WorkerWizardObj->getDataFromWizard(WorkerName, WorkerSurName) == true) {
      WorkerModel WorkerModelObject {};
      workerWidgetPtr = new WorkerWidget(nullptr,WorkerName,WorkerSurName);
      WorkerModelObject.addWorker(workerLayoutPtr, workerWidgetPtr);
      DataModelObject.saveWorkerLists(WorkerName, WorkerSurName);
   }
   else {
      return;
   }
}

void WorkerController::runDeleteWorker()
{
   WorkerDataModel DataModelObject {};
   WorkerModel WorkerModelObject {};
   WorkersRemovalDialog* DialogObject {new WorkersRemovalDialog(nullptr, DataModelObject.loadWorkerLists())};
   DialogObject->exec();

   int selectedWorkerNumberToDeleted {0};
   if (DialogObject->getDeletedWorkerNumber(selectedWorkerNumberToDeleted) == true) {
      WorkerModelObject.deleteWorker(selectedWorkerNumberToDeleted);
      DataModelObject.removeWorkerFromLists(selectedWorkerNumberToDeleted);
   }
   else {
      return;
   }
}

void WorkerController::runLoadWorker(QVBoxLayout* loadWorkerLayoutPtr)
{
   static int runFunctionCounter {0};
   if (runFunctionCounter == 1) {
      return;
   }
   else {
      QStringList workerNameList {};
      WorkerDataModel DataModelObject;
      WorkerModel WorkerModel {};
      workerNameList = DataModelObject.loadWorkerLists();

      if (workerNameList.isEmpty()) {
         return;
      }
      else {
         QString workerNameSurName {""};
         int loopCounter {0};
         for (const QString& loopIterator : workerNameList) {
            workerNameSurName = workerNameList.at(loopCounter);
            WorkerWidget *workerWidget {new WorkerWidget(nullptr,workerNameSurName)};
            WorkerModel.addWorker(loadWorkerLayoutPtr, workerWidget);
            loopCounter++;
         }
         runFunctionCounter++;
      }
   }
}
