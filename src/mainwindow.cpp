#include "./include/mainwindow.hpp"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
   setupUi(this);
   shiftController->setCalendarWidgetinLayout(CalendarLayout);
   shiftController->runLoadShift(CalendarLayout);

   WorkerController::runLoadWorker(WorkerLayout);
}

MainWindow::~MainWindow() { }

void MainWindow::CallAddWorker() { workerController->runAddWorker(WorkerLayout); }

void MainWindow::CallDeleteWorker() { workerController->runDeleteWorker(); }

void MainWindow::CallAddShift() { shiftController->runAddShift(); }

void MainWindow::CallDeleteShift() { shiftController->runDeleteShift(); }

void MainWindow::CallPrintWorkPlan() { printController->runStartPrint(); }