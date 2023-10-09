#include "../include/widgets/shiftwizard.hpp"

ShiftWizard::ShiftWizard(QWidget* parent, QStringList workerStringLists)
    : QWizard(parent)
{
   setupUi(this);
   WorkerComboBox->addItems(workerStringLists);
}

ShiftWizard::~ShiftWizard() { }

void ShiftWizard::getDataFromWizard(QString& nameSurname, int& selectedDayNumber)
{
   nameSurname       = WorkerComboBox->currentText();
   selectedDayNumber = DaySpinBox->value();
}

bool ShiftWizard::getAutoPlacementChoice() { return userAutoPlacementChoice_; }

void ShiftWizard::OffAutoPlacement() { userAutoPlacementChoice_ = false; }
void ShiftWizard::OnAutoPlacement() { userAutoPlacementChoice_ = true; }