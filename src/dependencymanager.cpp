#include "../include/dependencymanager.hpp"

DependencyManager::DependencyManager()
{
   QObject::connect(&mainWindow, &MainWindow::emitAddShift, dependencyShiftManager.get(), &DependencyShiftManager::callAddShift);
QObject::connect(&mainWindow, &MainWindow::emitDeleteShift, dependencyShiftManager.get(), &DependencyShiftManager::callDeleteShift);

   QObject::connect(&mainWindow, &MainWindow::emitAddWorker, depedencyWorkerManager.get(), &DependencyWorkerManager::callAddWorker);
   QObject::connect(&mainWindow, &MainWindow::emitDeleteWorker, depedencyWorkerManager.get(), &DependencyWorkerManager::callDeleteWorker);

   QObject::connect(&mainWindow, &MainWindow::emitPrintWorkPlan, this, &DependencyManager::callPrintWorkPlan);
   QObject::connect(depedencyWorkerManager.get(), &DependencyWorkerManager::emittedWorkerDeleted, dependencyShiftManager.get(), &DependencyShiftManager::handleDeleteWorker);
}

void DependencyManager::showMainWindow() { mainWindow.showMaximized(); }

void DependencyManager::callPrintWorkPlan() { printController.runStartPrint(); }