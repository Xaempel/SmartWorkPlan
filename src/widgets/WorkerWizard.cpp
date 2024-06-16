#include "include/widgets/WorkerWizard.hpp"

#include "./frontend/ui_workerwizard.h"

WorkerWizard::WorkerWizard(QWidget* parent)
    : QWizard(parent)
    , ui(new Ui::WorkerWizard)
{
   ui->setupUi(this);
}

WorkerWizard::~WorkerWizard() { }

bool WorkerWizard::getDataFromWizard(QString& firstName, QString& lastName)
{
   QString workerFirstName {ui->WorkerNameLineEdit->text()};
   QString workerLastName {ui->WorkerSurNameLineEdit->text()};

   if (workerFirstName.isEmpty() || workerLastName.isEmpty()) {
      QMessageBox::information(nullptr, "Input is incorrect", "The input is empty");
      return false;
   }
   else if (workerLastName.size() > 20 || workerFirstName.size() > 20) {
      QMessageBox::information(nullptr, "Input is incorrect", "The input is too long");
      return false;
   }
   else {
      firstName = workerFirstName;
      lastName  = workerLastName;
      return true;
   }
}
