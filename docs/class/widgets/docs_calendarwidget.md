# Calendar Widget 
[Home](../../ReadMe.md) 
 
The Calendar Widget class is a responsible for calendar widget

## Inheritance
  
this class inherit on QFrame and Ui class 

## Class headers

    QFrame
    QVector

    frontend/ui_calendarwidget.h

## Class methods 

###  explicit CalendarWidget(QWidget *parent = nullptr);

ten konstruktor ustawia ui

### ~CalendarWidget();

this is default destructor

### void getCalendarFieldWidgetLayoutPtr(QGridLayout *&LayoutPtr);

this methods set a layout from argument to layout of calendar widget  so you can add calendar field widgets