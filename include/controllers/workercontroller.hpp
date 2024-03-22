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

#include "../models/datamodel.hpp"
#include "../models/workermodel.hpp"
#include "../widgets/removaldialog/workersremovaldialog.hpp"
#include "../widgets/workerwidget.hpp"
#include "../widgets/workerwizard.hpp"

#include <QObject>
#include <QVBoxLayout>

/// @brief This class is responsible for managing employee 
class WorkerController : public QObject {
   Q_OBJECT
   public:
   WorkerController(DataModel& dataModelObj);

   public slots:
   /// @brief This method is responsible for loading employees into the layout from the argument
   void runLoadWorker(QVBoxLayout* loadWorkerLayoutPtr);
   /// @brief This method is responsible for add worker
   void runAddWorker(QVBoxLayout* workerLayoutPtr);
   /// @brief This method is responsible for delete worker
   void runDeleteWorker();

   protected:
   /// @brief This method return deleted worker name this methods used for auto delete worker from shift 
   QString getDeletedWorkerName();

   private:
   WorkerWidget* workerWidgetPtr {nullptr};
   QString nameDeletedWorker_ {""};
   static QList<QWidget*> workerWidgetList;

   DataModel* dataModelPtr {nullptr};

   friend class DependencyWorkerManager;
};