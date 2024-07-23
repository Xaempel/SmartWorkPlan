#include "include/widgets/CalendarFieldWidget.hpp"

#include "../frontend/ui_calendarfieldwidget.h"

using ShiftsData = QList<QPair<QLabel*, QString>>;

CalendarFieldWidget::CalendarFieldWidget(QWidget* parent, int DayCounter)
    : QFrame(parent)
    , ui(new Ui::CalendarFieldWidget)
{
   ui->setupUi(this);
   ui->DateLabel->setText(QString::number(DayCounter));
}

CalendarFieldWidget::~CalendarFieldWidget() { }

void CalendarFieldWidget::addShiftWidget(QLabel* shiftWidget, QString name)
{
   shiftsData.append(QPair<QLabel*, QString>(shiftWidget, name));
   ui->WorkerNameandSurNameLayout->addWidget(shiftWidget);
}

ShiftsData CalendarFieldWidget::getShiftDataList()
{
   return shiftsData;
}

void CalendarFieldWidget::deleteShiftfromCalendarFieldWidget(int indexofShift)
{
   shiftsData.at(indexofShift).first->deleteLater();
   shiftsData.removeAt(indexofShift);
}