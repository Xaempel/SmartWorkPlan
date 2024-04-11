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

#include "modelsinteface/ishiftmodel.hpp"

#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

/// @brief This class is responsible for shift system
class ShiftModel : public InterFace::IShiftModel {
   public:
   ShiftModel(QVector<QLabel*>& workerWidgetVector);
   
   /// @brief This method is a derived method from the IShitData class and is used to add employees to the shift
   void addShift(QVBoxLayout* layouttoAddShift, QString workerName) override;

   /// @brief This method is a derived method from the IShitData class and is used to delete employees from the shift
   void deleteShift(int shiftNumbertoDelete) override;

   private:
   QVector<QLabel*>* workerWidgetVectorPtr {nullptr};
   static int workerWidgetNumber;
};