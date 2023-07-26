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
      WorkerModelObject.addWorker(workerLayoutPtr, WorkerName, WorkerSurName);
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
      QStringList WorkerNameList {};
      WorkerDataModel DataModelObject;
      WorkerModel WorkerModelObject {};
      WorkerNameList = DataModelObject.loadWorkerLists();

      if (WorkerNameList.isEmpty()) {
         return;
      }
      else {
         QString workerNameSurName {""};
         for (int i = 0; i < WorkerNameList.size(); i++) {
            workerNameSurName = WorkerNameList.at(i);
            WorkerModelObject.addWorker(loadWorkerLayoutPtr, workerNameSurName, "");
         }
         runFunctionCounter++;
      }
   }
}
