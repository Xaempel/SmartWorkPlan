# Workers Wizard
[Home](../../ReadMe.md) 

This class is responsible for a process of create worker

## Inheritance

this class inherit on QWizard and Ui class 

## Class headers

    frontend/ui_workerwizard.h

    QMessageBox
    QString
    QWizard

## Class methods 

### WorkerWizard(QWidget* parent = nullptr);

this constructor setup Ui

### ~WorkerWizard();

this is default desctructor

### bool getDataFromWizard(QString& Name, QString& SurName);

this method saves the wizard data in the variable from the argument