# Print model
[Home](../../ReadMe.md) 
 
The Print model class is responsible for the business logic of the printing system

## Inheritance
 
QObject 
 
## Class headers

    QObject
    QPaintDevice
    QPainter
    QPrinter
    QStringList

## Class methods 
 
### void startPrint(QStringList workerNameLists);
   
this methods print a worker plan 

### Privte methods

### void paintStaticElements(QPainter& painter, int workerNumber);

this method is a helper for the main startPrint method and shares the code responsible for printing the static elements of the class (i.e. those that, regardless of the circumstances, do not change) 

### void paintWorker(QPainter& painter, QStringList workerNameLists);

this method is the same as the previous one also has the task of splitting the code from the main method only this method is responsible for printing the elements of the employee's frame names surnames etc