/******************************************************************************
**                                                                            **
**  Copyright (C) [2023] [Xaempel]                                            **
**                                                                            **
**  This file is part of [SmartWorkPlan].                                     **
**  [SmartWorkPlan] is free software: you can redistribute it and/or          **
**  modify it under the terms of the GNU General Public License as published  **
**  by the Free Software Foundation, either version 2 of the License, or any  **
**  later version.                                                            **
**                                                                            **
**  [SmartWorkPlan] is distributed in the hope that it will be                **
**  useful, but WITHOUT ANY WARRANTY; without even the implied warranty of    **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             **
**  GNU General Public License for more details.                              **
**                                                                            **
**  You should have received a copy of the GNU General Public License along   **
**  with [SmartWorkPlan].  If not, see <https://www.gnu.org/licenses/>.       **
**                                                                            **
**  This project uses the Qt framework, which is licensed under the GNU       **
**  General Public License (GPL) version 2 or later. The full text of the     **
**  GPL license can be found in the LICENSE file.                             **
**                                                                            **
**  Qt is a cross-platform application framework maintained by The Qt Company.**
**  You can find more information about Qt and its licensing at               **
**  https://www.qt.io/.                                                       **
**                                                                            **
******************************************************************************/
#pragma once

#include "controllers/printcontroller.hpp"
#include "depmanagerhelpers/dependencyshiftmanager.hpp"
#include "depmanagerhelpers/dependencyworkermanager.hpp"
#include "mainwindow.hpp"
#include "models/shiftmodel.hpp"

#include <memory>

class DependencyManager : public QObject {
   Q_OBJECT
   public:
   DependencyManager();
   void showMainWindow();

   private slots:

   void callPrintWorkPlan();

   private:
   std::unique_ptr<MainWindow> mainWindow = std::make_unique<MainWindow>(nullptr);
   QVBoxLayout* calendarLayout {};

   static QVector<QLabel*> workerWidgetVec;
   static QVector<CalendarFieldWidget*> calendarFieldWidgetVec;

   std::unique_ptr<ShiftModel> shiftModel                          = std::make_unique<ShiftModel>(workerWidgetVec);
   std::unique_ptr<DependencyShiftManager> dependencyShiftManager  = std::make_unique<DependencyShiftManager>(mainWindow->getCalendarLayout(), shiftModel.get(), &calendarFieldWidgetVec);
   std::unique_ptr<DependencyWorkerManager> depedencyWorkerManager = std::make_unique<DependencyWorkerManager>(mainWindow->getWorkerLayout());
   PrintController printController;
};