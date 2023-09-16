-- ShiftController: The Docs was created in version 0.7.1 

--- Inherits: public QObject

--- Class goals: this class is responsible for managing employee 

---- public slots Methods:
1. void runLoadWorker(QVBoxLayout* loadWorkerLayoutPtr);

    this method is responsible for loading employees into the layout from the argument

2. void runAddWorker(QVBoxLayout* workerLayoutPtr);

    this method is responsible for add worker

3. void runDeleteWorker();
    this method is responsible for delete worker

--- protected Methods:

1. QString getDeletedWorkerName();

    this method return deleted worker name this methods used for auto delete worker from shift 

[Home](../../ReadMe.md)