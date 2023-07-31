#include "./include/mainwindow.hpp"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
   setupUi(this);
   ShiftController::SetCalendarWidgetinLayout(CalendarLayout);
   ShiftController::runLoadShift(CalendarLayout);

   WorkerController::runLoadWorker(WorkerLayout);
}

MainWindow::~MainWindow() { }

void MainWindow::CallAddWorker()
{
   workerController->runAddWorker(WorkerLayout);
}

void MainWindow::CallDeleteWorker()
{
   workerController->runDeleteWorker();
}

void MainWindow::CallAddShift()
{
   shiftController->runAddShift();
}