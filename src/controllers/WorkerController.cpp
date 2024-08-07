#include "include/controllers/WorkerController.hpp"

// #include <QMessageBox>
const QString workerDataSectionName {"worker section"};

WorkerController::WorkerController(DataModel& dataModelObj)
    : dataModelPtr(&dataModelObj)
{
}

void WorkerController::runAddWorker(QVBoxLayout* workerLayoutPtr)
{
   QString WorkerName {""};
   QString WorkerSurName {""};

   WorkerWizard* WorkerWizardObj {new WorkerWizard};
   WorkerWizardObj->exec();

   if (WorkerWizardObj->getDataFromWizard(WorkerName, WorkerSurName) == true) {
      WorkerModel WorkerModelObject(&workerWidgetList);
      workerWidgetPtr = new WorkerWidget(nullptr, WorkerName, WorkerSurName);
      WorkerModelObject.addWorker(workerLayoutPtr, workerWidgetPtr);
      dataModelPtr->save(std::nullopt, workerDataSectionName, WorkerName + " " + WorkerSurName);
   }
   else {
      return;
   }
}

void WorkerController::runDeleteWorker()
{
   WorkerModel WorkerModelObject(&workerWidgetList);
   QVariantList dataList {};

   QStringList workerNameList {};

   dataModelPtr->load("data.json", workerDataSectionName, dataList);

   workerNameList = ToolsforDataManipulation::convertVariantToRequiredType<QString>(dataList);

   WorkersRemovalDialog* DialogObject {new WorkersRemovalDialog(nullptr, workerNameList)};
   DialogObject->exec();

   if (workerNameList.size() != 0) {
      int selectedWorkerNumberToDeleted {0};
      if (DialogObject->getDeletedWorkerNumber(selectedWorkerNumberToDeleted) == true) {
         nameDeletedWorker_ = workerNameList.at(selectedWorkerNumberToDeleted);
         WorkerModelObject.deleteWorker(selectedWorkerNumberToDeleted);
         dataModelPtr->deleteDatafromFile("data.json", workerDataSectionName, selectedWorkerNumberToDeleted);
      }
      else {
         return;
      }
   }
   else {
      QMessageBox::warning(nullptr,"Any Workers to delete not exist","You don't have any workers to delete");
   }
}

void WorkerController::runLoadWorker(QVBoxLayout* loadWorkerLayoutPtr)
{
   static int runFunctionCounter {0};
   QVariantList dataList {};
   if (runFunctionCounter == 1) {
      return;
   }
   else {
      WorkerModel WorkerModel(&workerWidgetList);
      dataModelPtr->load("data.json", workerDataSectionName, dataList);

      if (dataList.isEmpty()) {
         return;
      }
      else {
         QStringList workerNameList {};
         workerNameList = ToolsforDataManipulation::convertVariantToRequiredType<QString>(dataList);
         int loopCounter {0};
         for (const auto& loopIterator : workerNameList) {
            QString workerNameSurName = workerNameList.at(loopCounter);
            WorkerWidget* workerWidget {new WorkerWidget(nullptr, workerNameSurName)};
            WorkerModel.addWorker(loadWorkerLayoutPtr, workerWidget);
            loopCounter++;
         }
         runFunctionCounter++;
      }
   }
}

QString WorkerController::getDeletedWorkerName() { return nameDeletedWorker_; }

QList<QWidget*> WorkerController::workerWidgetList {};