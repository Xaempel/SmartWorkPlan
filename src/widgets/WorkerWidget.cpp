#include "include/widgets/WorkerWidget.hpp"

#include "./frontend/ui_workerwidget.h"

WorkerWidget::WorkerWidget(QWidget* parent)
    : QFrame(parent)
    , ui(new Ui::WorkerWidget)
{
   ui->setupUi(this);
}

WorkerWidget::WorkerWidget(QWidget* parent, QString firstName, QString lastName)
    : QFrame(parent)
    , ui(new Ui::WorkerWidget)
{
   ui->setupUi(this);
   setNameandSurName(firstName, lastName);
}

void WorkerWidget::setNameandSurName(QString firstName, QString lastName)
{
   ui->WorkerNameLabel->setText(firstName + "  " + lastName);
}