#include "include/widgets/CalendarWidget.hpp"

#include "../frontend/ui_calendarwidget.h"

CalendarWidget::CalendarWidget(QWidget* parent)
    : QFrame(parent), ui(new Ui::CalendarWidget)
{
   ui->setupUi(this);
}

CalendarWidget::~CalendarWidget() { }

void CalendarWidget::addWidgettoCalendar(QWidget *widget,int dayCounter){
   ui->CalendarWidgetLayout->addWidget(widget,dayCounter / 7, dayCounter % 7);
}