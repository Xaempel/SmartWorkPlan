#include "../include/widgets/LicenseInformationWidget.hpp"

#include "../frontend/ui_licenseinformationwidget.h"

LicenseInformationsWidget::LicenseInformationsWidget(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::LicenseInformationsWidget)
{
   ui->setupUi(this);
}