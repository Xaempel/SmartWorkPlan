#include "../include/dependencymanager.hpp"

DependencyManager::DependencyManager()
{
   QObject::connect(mainWindow.get(), &MainWindow::emitAddShift, dependencyShiftManager.get(), &DependencyShiftManager::callAddShift);

   QObject::connect(mainWindow.get(), &MainWindow::emitAddWorker, depedencyWorkerManager.get(), &DependencyWorkerManager::callAddWorker);
   QObject::connect(mainWindow.get(), &MainWindow::emitDeleteWorker, depedencyWorkerManager.get(), &DependencyWorkerManager::callDeleteWorker);

   QObject::connect(mainWindow.get(), &MainWindow::emitPrintWorkPlan, this, &DependencyManager::callPrintWorkPlan);
}

void DependencyManager::showMainWindow() { mainWindow->showMaximized(); }

void DependencyManager::callPrintWorkPlan() { printController.runStartPrint(); }

QVector<QLabel*> DependencyManager::workerWidgetVec;
QVector<CalendarFieldWidget*> DependencyManager::calendarFieldWidgetVec;