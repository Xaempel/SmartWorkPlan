-- PrintModel: The Docs was created in version 0.7.1 

--- Inherits: public QObject

--- Class goals: this class is responsible for print system

---- public Methods:
1. void startPrint(QStringList workerNameLists);
   
   Printing a worker schedule

---- private Methods:
1. void paintStaticElements(QPainter& painter, int workerNumber);

   this function print static elements in worker schedule

2. void paintWorker(QPainter& painter, QStringList workerNameLists);

   this function draws workers on worker schedule

[Home](../../ReadMe.md)