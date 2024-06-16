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

#include <QFrame>
#include <QLabel>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui {
   class CalendarFieldWidget;
}
QT_END_NAMESPACE

/// @brief This class is a calendar field
class CalendarFieldWidget : public QFrame {
   using ShiftsData = QList<QPair<QLabel*, QString>>;

   public:
   explicit CalendarFieldWidget(QWidget* parent = nullptr, int DayCounter = 0);
   ~CalendarFieldWidget();

   /// @brief a method add shift widget to layout in the class CalendarFieldWidget
   void addShiftWidget(QLabel* shiftWidget, QString name);
   ShiftsData getShiftDataList();

   private:
   Ui::CalendarFieldWidget* ui {nullptr};

   ShiftsData shiftsData;
};