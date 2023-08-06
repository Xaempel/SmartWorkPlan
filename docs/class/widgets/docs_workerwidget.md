# Workers Widget
[Home](../../ReadMe.md) 

This class is responsible for a worker widget

## Inheritance

this class inherit on QFrame and Ui class 

## Class headers

    frontend/ui_workerwidget.h

    QFrame
## Class methods 

### WorkerWidget(QWidget* parent = nullptr);

this is constructor to a responsible to setup ui

### WorkerWidget(QWidget* parent = nullptr, QString Name = "", QString SurName = "");

this is constructor to a responsible to setup ui and setup Worker name and last name

### void setNameandSurName(QString Name, QString SurName);

this methods sets Name and SurName for worker widget