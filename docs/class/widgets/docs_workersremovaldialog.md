# Workers Removal dialog
[Home](../../ReadMe.md) 

This class is responsible for collecting data from the user regarding the removal of an employee

## Inheritance

this class inherit on QDialog and Ui class 

## Class headers

    QDialog
    QStringList

## Class methods 

### WorkersRemovalDialog(QWidget* parent = nullptr, QStringList     WorkerNameSurNameLists = {});

This constructor sets the ui and loads the employee's first and last name into the combo box

### ~WorkersRemovalDialog();

this is a default destructor

### bool getDeletedWorkerNumber(int& WorkerNumber);
this method saves the Worker Number selected by the user to the variable from the argument

### Private Methods

### void UpdateNumberDeletedWorker();

this method updates the variable in the Worker removal Dialog class that is responsible for the number of the removed employee