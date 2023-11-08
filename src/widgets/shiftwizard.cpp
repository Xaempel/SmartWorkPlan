#include "../include/widgets/shiftwizard.hpp"

#include "../frontend/ui_shiftwizard.h"

ShiftWizard::ShiftWizard(QWidget* parent, QStringList workerStringLists)
    : QWizard(parent)
    , ui(new Ui::ShiftWizard)
{
   ui->setupUi(this);
   ui->WorkerComboBox->addItems(workerStringLists);
}

ShiftWizard::~ShiftWizard() { }

void ShiftWizard::getDataFromWizard(QString& nameSurname, int& selectedDayNumber)
{
   nameSurname       = ui->WorkerComboBox->currentText();
   selectedDayNumber = ui->DaySpinBox->value();
}

bool ShiftWizard::getAutoPlacementChoice() { return userAutoPlacementChoice_; }

void ShiftWizard::OffAutoPlacement() { userAutoPlacementChoice_ = false; }
void ShiftWizard::OnAutoPlacement() { userAutoPlacementChoice_ = true; }