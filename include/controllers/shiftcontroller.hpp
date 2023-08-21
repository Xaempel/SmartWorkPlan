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

#include "../models/modelsinteface/ishiftdatamodel.hpp"
#include "../models/modelsinteface/ishiftmodel.hpp"
#include "../models/modelsinteface/iworkerdatamodel.hpp"
#include "../widgets/calendarfieldwidget.hpp"
#include "../widgets/calendarwidget.hpp"
#include "../widgets/removaldialog/shiftremovaldialog.hpp"
#include "../widgets/shiftwizard.hpp"

#include <QGridLayout>
#include <QObject>
#include <QVBoxLayout>
#include <QVector>
#include <memory>

class ShiftController : public QObject {
   using IShiftDataModel  = InterFace::IShiftDataModel;
   using IShiftModel      = InterFace::IShiftModel;
   using IWorkerDataModel = InterFace::IWorkerDataModel;

   public:
   explicit ShiftController(IShiftDataModel* shiftDataModel, IWorkerDataModel* workerDataModel, IShiftModel* shiftModel);
   void setCalendarWidgetinLayout(QVBoxLayout* LayoutPtr);
   void runLoadShift(QVBoxLayout* LayoutPtr);
   void runAddShift();
   void runDeleteShift();

   private:
   static QVector<CalendarFieldWidget*> calendarFieldWidgetVec;

   IShiftModel* shiftModelPtr {nullptr};
   IShiftDataModel* shiftDataModelPtr {nullptr};
   IWorkerDataModel* workerDataModelPtr {nullptr};
   QVBoxLayout* workerShiftLayoutPtr_ {nullptr};
};