#include "./include/MainWindow.hpp"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
   setupUi(this);
   QObject::connect(ActionAddShift, &QAction::triggered, this, &MainWindow::emitAddShift);
   QObject::connect(ActionDeleteShifts, &QAction::triggered, this, &MainWindow::emitDeleteShift);

   QObject::connect(ActionAddWorker, &QAction::triggered, this, &MainWindow::emitAddWorker);
   QObject::connect(ActionDeleteWorker, &QAction::triggered, this, &MainWindow::emitDeleteWorker);

   QObject::connect(ActionPrintWorkPlan, &QAction::triggered, this, &MainWindow::emitPrintWorkPlan);
}

MainWindow::~MainWindow() { }

QVBoxLayout* MainWindow::getCalendarLayout() { return CalendarLayout; }
QVBoxLayout* MainWindow::getWorkerLayout() { return WorkerLayout; }