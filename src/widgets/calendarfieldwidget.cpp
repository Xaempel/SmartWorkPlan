#include "../include/widgets/calendarfieldwidget.hpp"

CalendarFieldWidget::CalendarFieldWidget(QWidget* parent, int DayCounter)
    : QFrame(parent)
{
   setupUi(this);
   DateLabel->setText(QString::number(DayCounter));
}

CalendarFieldWidget::~CalendarFieldWidget() { }

void CalendarFieldWidget::getPointertoWorkerShiftPlace(QVBoxLayout*& Ptr)
{
   Ptr = WorkerNameandSurNameLayout;
}