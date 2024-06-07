#include "../include/dependencymanager.hpp"

DependencyManager::DependencyManager()
{
   QObject::connect(&mainWindow, &MainWindow::emitAddShift, dependencyShiftManager.get(), &DependencyShiftManager::callAddShift);

   QObject::connect(&mainWindow, &MainWindow::emitAddWorker, depedencyWorkerManager.get(), &DependencyWorkerManager::callAddWorker);
   QObject::connect(&mainWindow, &MainWindow::emitDeleteWorker, depedencyWorkerManager.get(), &DependencyWorkerManager::callDeleteWorker);

   QObject::connect(&mainWindow, &MainWindow::emitPrintWorkPlan, this, &DependencyManager::callPrintWorkPlan);
}

void DependencyManager::showMainWindow() { mainWindow.showMaximized(); }

void DependencyManager::callPrintWorkPlan() { printController.runStartPrint(); }