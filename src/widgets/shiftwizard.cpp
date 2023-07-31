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