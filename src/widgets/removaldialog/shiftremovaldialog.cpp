#include "../include/widgets/removaldialog/shiftremovaldialog.hpp"

ShiftRemovalDialog::ShiftRemovalDialog(QWidget* parent, QVector<QPair<QString, int>> shiftDataVec)
    : QDialog(parent)
{
   setupUi(this);
   int loopCounter {0};
   for (const auto& i : shiftDataVec) {
      auto nameVar = shiftDataVec.at(loopCounter).first;
      auto dateVar = shiftDataVec.at(loopCounter).second + 1;

      WorkerListsComboBox->addItem(nameVar + "  " + QString::number(dateVar));
      loopCounter++;
   }
}

void ShiftRemovalDialog::getDataFromWizard(int& shiftData) { shiftData = shiftData_;  }

void ShiftRemovalDialog::updateWizardData()
{
   shiftData_ = WorkerListsComboBox->currentIndex();
   this->close();
}