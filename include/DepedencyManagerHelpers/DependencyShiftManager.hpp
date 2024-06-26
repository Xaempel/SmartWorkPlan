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

#include "../controllers/DataControllers/ShiftDataController.hpp"
#include "include/controllers/ShiftController.hpp"
#include "include/models/DataModel.hpp"

class DependencyShiftManager : public QObject {
   using ShiftDataController = DataControllers::ShiftDataController;

   Q_OBJECT
   public:
   explicit DependencyShiftManager(QVBoxLayout* calendarLayout);
   public slots:
   void callAddShift();
   void callDeleteShift();
   void handleDeleteWorker(QString  nameofDeletedWorker);

   private:
   void refreshPointer();

   QVector<CalendarFieldWidget*> calendarFieldWidgets {};

   std::unique_ptr<DataModel> dataModel = std::make_unique<DataModel>();
   std::unique_ptr<ShiftDataController> shiftDataController {nullptr};
   std::unique_ptr<ShiftController> shiftController {nullptr};
};