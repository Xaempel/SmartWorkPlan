#include "./include/mainwindow.hpp"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
   setupUi(this);
   WorkerController::runLoadWorker(WorkerLayout);
}

MainWindow::~MainWindow() {}

void MainWindow::CallAddWorker()
{
   WorkerController::runAddWorker(WorkerLayout);
}

void MainWindow::CallDeleteWorker(){
   WorkerController::runDeleteWorker();
}