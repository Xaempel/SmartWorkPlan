#include "../include/widgets/calendarfieldwidget.hpp"

#include "../frontend/ui_calendarfieldwidget.h"

CalendarFieldWidget::CalendarFieldWidget(QWidget* parent, int DayCounter)
    : QFrame(parent)
    , ui(new Ui::CalendarFieldWidget)
{
   ui->setupUi(this);
   ui->DateLabel->setText(QString::number(DayCounter));
}

CalendarFieldWidget::~CalendarFieldWidget() { }

void CalendarFieldWidget::getPointertoWorkerShiftPlace(QVBoxLayout*& Ptr)
{
   Ptr = ui->WorkerNameandSurNameLayout;
}