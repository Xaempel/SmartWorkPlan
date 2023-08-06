# Shift Controller 
[Home](../../ReadMe.md) 

The Shift Controller class is responsible for shift. It contains methods to set Calendar widget, load and add shift. 
 
## Inheritance
 
QObject 
 
## Class headers

    models/shiftdatamodel.hpp
    models/shiftmodel.hpp
    models/workerdatamodel.hpp
    widgets/calendarfieldwidget.hpp
    widgets/calendarwidget.hpp
    widgets/shiftwizard.hpp

    QGridLayout
    QObject
    QVBoxLayout
    QVector

## Class methods 
 
### static void SetCalendarWidgetinLayout(QVBoxLayout* LayoutPtr);

Inserts Calendar widget for layout from argument

### static void runLoadShift(QVBoxLayout* LayoutPtr);

Gets a list of employee names from LoadShift and creates the widgets and inserts widgets for layout from the argument

### void runAddShift();

Runs a wizard for shift and next gets data on wizard and final insert data for suitable calendarfieldwidget 