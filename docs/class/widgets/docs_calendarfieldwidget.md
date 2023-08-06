# Calendar Field Widget 
[Home](../../ReadMe.md) 
 
The Calendar Field Widget class is a responsible for calendar field widget

## Inheritance
  
this class inherit on QFrame and Ui class 

## Class headers

    frontend/ui_calendarfieldwidget.h

    QFrame
    QVBoxLayout

## Class methods 

### explicit CalendarFieldWidget(QWidget* parent = nullptr, int DayCounter = 0);

this constructor setup Ui and set Calendar Field widget number of day

### ~CalendarFieldWidget();

this a basic destructor

### void getPointertoWorkerShiftPlace(QVBoxLayout*& Ptr);

this method sets the layout from the argument to your layout for adding employees
