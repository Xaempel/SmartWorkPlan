# Worker Controller 
[Home](../../ReadMe.md) 

The Worker Controller class is responsible for worker. It contains methods to add, delete and load employees. 
 
## Inheritance
 
QObject 
 
## Class headers

    models/workerdatamodel.hpp
    models/workermodel.hpp

    widgets/workersremovaldialog.hpp
    widgets/workerwizard.hpp

    QObject
    QVBoxLayout

## Class methods 
 
###  static void runLoadWorker(QVBoxLayout* loadWorkerLayoutPtr)  

this method reads previous employees and this basis adds employees to the layout from the argument   
 
### void runAddWorker(QVBoxLayout* workerLayoutPtr)  
 
method add worker to layout from the argument
 
###  void runDeleteWorker()  
 
this methods run a Workers Removal Dialog and for basis on user selected option delete worker