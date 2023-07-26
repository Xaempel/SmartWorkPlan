#include "./include/widgets/workerwidget.hpp"

WorkerWidget::WorkerWidget(QWidget* parent)
    : QFrame(parent)
{
   setupUi(this);
}

WorkerWidget::WorkerWidget(QWidget* parent, QString Name, QString SurName)
    : QFrame(parent)
{
   setupUi(this);
   setNameandSurName(Name, SurName);
}

void WorkerWidget::setNameandSurName(QString Name, QString SurName)
{
   WorkerNameLabel->setText(Name + "  " + SurName);
}