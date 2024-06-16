#include "include/widgets/RemovalDialogs/ShiftRemovalDialog.hpp"

#include "../frontend/ui_shiftremovaldialog.h"

#include <QLabel>

ShiftRemovalDialog::ShiftRemovalDialog(QWidget* parent, QStringList shifts)
    : QDialog(parent)
    , ui(new Ui::ShiftRemovalDialog)
{
   ui->setupUi(this);
   QObject::connect(ui->AcceptButton, &QPushButton::clicked, this, &ShiftRemovalDialog::buttonofAcceptWasClicked);
   QObject::connect(ui->CancellButton, &QPushButton::clicked, this, [this]() { this->close(); });

   for (auto i : shifts) {
      int shiftDeletedDay {i.section(' ', 0, 0).toInt()};
      QString workerName {i.section(' ', 1)};

      shiftDeletedDay++;
      ui->WorkersShiftsComboBox->addItem(QString::number(shiftDeletedDay) + " " + workerName);
   }
}

QPair<int, QString> ShiftRemovalDialog::getSelectedShiftsData()
{
   return QPair<int, QString>(selectedShiftDay_, selectedWorkerName_);
}

void ShiftRemovalDialog::buttonofAcceptWasClicked()
{
   QString rawText = ui->WorkersShiftsComboBox->currentText();

   selectedShiftDay_   = rawText.section(' ', 0, 0).toInt();
   selectedWorkerName_ = rawText.section(' ', 1);

   selectedShiftDay_--;

   this->close();
}