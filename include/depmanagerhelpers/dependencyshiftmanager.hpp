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

#include "../controllers/datacontrollers/shiftdatacontroller.hpp"
#include "../controllers/shiftcontroller.hpp"
#include "../models/datamodel.hpp"
#include "../models/modelsinteface/ishiftmodel.hpp"

class DependencyShiftManager : public QObject {
   using ShiftDataController = DataControllers::ShiftDataController;

   Q_OBJECT
   public:
   explicit DependencyShiftManager(QVBoxLayout* calendarLayout, InterFace::IShiftModel* ishiftModel);
   public slots:
   void callAddShift();

   private:
   void refreshPointer();

   InterFace::IShiftModel* ishiftModelPtr {nullptr};
   QVector<CalendarFieldWidget*> calendarFieldWidgets {};

   std::unique_ptr<DataModel> dataModel = std::make_unique<DataModel>();
   std::unique_ptr<ShiftDataController> shiftDataController {nullptr};
   std::unique_ptr<ShiftController> shiftController {nullptr};
};