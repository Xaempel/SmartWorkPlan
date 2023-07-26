#include "./include/widgets/workersremovaldialog.hpp"

WorkersRemovalDialog::WorkersRemovalDialog(QWidget* parent, QStringList WorkerNameSurNameLists)
{
   setupUi(this);
   WorkerListsComboBox->addItems(WorkerNameSurNameLists);
}

WorkersRemovalDialog::~WorkersRemovalDialog() { }

bool WorkersRemovalDialog::getDeletedWorkerNumber(int& WorkerNumber)
{
   if (AcceptedDialog == true) {
      (WorkerNumber = workerNumber_);
      return true;
   }
   else {
      return false;
   }
}

void WorkersRemovalDialog::UpdateNumberDeletedWorker()
{
   (workerNumber_ = WorkerListsComboBox->currentIndex());
   (AcceptedDialog = true);
}