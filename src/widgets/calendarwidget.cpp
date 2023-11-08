#include "../include/widgets/calendarwidget.hpp"

#include "../frontend/ui_calendarwidget.h"

CalendarWidget::CalendarWidget(QWidget* parent)
    : QFrame(parent), ui(new Ui::CalendarWidget)
{
   ui->setupUi(this);
}

CalendarWidget::~CalendarWidget() { }

void CalendarWidget::getCalendarFieldWidgetLayoutPtr(QGridLayout*& layouttoGetCalendarFieldWidgetLayout)
{
   layouttoGetCalendarFieldWidgetLayout = ui->CalendarWidgetLayout;
}