#include "../include/widgets/calendarwidget.hpp"

CalendarWidget::CalendarWidget(QWidget* parent)
    : QFrame(parent)
{
   setupUi(this);
}

CalendarWidget::~CalendarWidget() { }

void CalendarWidget::getCalendarFieldWidgetLayoutPtr(QGridLayout*& LayoutPtr)
{
   LayoutPtr = CalendarWidgetLayout;
}