#include "./include/widgets/workerwizard.hpp"

WorkerWizard::WorkerWizard(QWidget* parent)
    : QWizard(parent)
{
   setupUi(this);
}
WorkerWizard::~WorkerWizard() { }

bool WorkerWizard::getDataFromWizard(QString& Name, QString& SurName)
{
   QString WName {WorkerNameLineEdit->text()};
   QString WSurName {WorkerSurNameLineEdit->text()};

   if (WName.isEmpty() || WSurName.isEmpty()) {
      QMessageBox::information(nullptr, "Input is incorrect", "The input is empty");
      return false;
   }
   else if (WSurName.size() > 20 || WName.size() > 20) {
      QMessageBox::information(nullptr, "Input is incorrect", "The input is too long");
      return false;
   }
   else {
      Name    = WName;
      SurName = WSurName;
      return true;
   }
}
