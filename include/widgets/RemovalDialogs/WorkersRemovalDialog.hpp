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

#include "./frontend/ui_workersremovaldialog.h"

#include <QDialog>
#include <QStringList>


/// @brief The class is a removal dialog of workers 
class WorkersRemovalDialog : public QDialog, private Ui::WorkersRemovalDialog {
   Q_OBJECT
   public:
   WorkersRemovalDialog(QWidget* parent = nullptr, QStringList WorkerNameSurNameLists = {});
   ~WorkersRemovalDialog();

   /// @brief  This method saves the Worker Number selected by the user to the variable from the argument.
   /// @return Return value for check whether data is put to WorkerNumber
   bool getDeletedWorkerNumber(int& WorkerNumber);

   private:
   int workerNumber_ {0};
   bool AcceptedDialog {false};

   private slots:

   /// @brief This method updates the variable in the Worker removal Dialog class that is responsible for the number of the removed employee
   void UpdateNumberDeletedWorker();
};