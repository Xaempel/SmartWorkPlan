/******************************************************************************
** Copyright (C) [2023] [Xaempel]                                            **
**                                                                           **
** This file is part of [SmartWorkPlan].                                     **
** [SmartWorkPlan] is free software: you can redistribute it and/or          **
** modify it under the terms of the GNU General Public License as published  **
** by the Free Software Foundation, either version 2 of the License, or any  **
** later version.                                                            **
**                                                                           **
** [SmartWorkPlan] is distributed in the hope that it will be                **
** useful, but WITHOUT ANY WARRANTY; without even the implied warranty of    **
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the              **
** GNU General Public License for more details.                              **
**                                                                           **
** You should have received a copy of the GNU General Public License along   **
** with [SmartWorkPlan]. If not, see https://www.gnu.org/licenses/.          **
**                                                                           **
** This project uses the Qt framework, which is licensed under the GNU       **
** General Public License (GPL) version 2 or later. The full text of the     **
** GPL license can be found in the LICENSE file.                             **
**                                                                           **
** Qt is a cross-platform application framework maintained by The Qt Company.**
** You can find more information about Qt and its licensing at               **
** https://www.qt.io/.                                                       **
**                                                                           **
** This project also uses Catch2, a C++ framework for unit tests.            **
** Catch2 is licensed under the Boost Software License, Version 1.0.         **
** You can find more information about Catch2 and its licensing at           **
** https://github.com/catchorg/Catch2/blob/devel/LICENSE.txt                 **
**                                                                           **
******************************************************************************/

#include "../include/models/shiftmodel.hpp"

#include <QApplication>
#include <catch2/catch.hpp>
#include <memory>

int argc {0};
QApplication testApp(argc, nullptr);

struct ShiftModelTestData {
   QVBoxLayout layoutforTest {};
   QVector<QLabel*> workerWidgetVec {};
   std::unique_ptr<ShiftModel> shiftModel = std::make_unique<ShiftModel>(workerWidgetVec);
};

TEST_CASE_METHOD(ShiftModelTestData, "ShiftModel::addShift", "[ShiftModel]")
{
   shiftModel->addShift(&layoutforTest, "Test worker name in addShift test");
   REQUIRE(layoutforTest.count() == 1);
   shiftModel->deleteShift(0);
}

TEST_CASE_METHOD(ShiftModelTestData, "ShiftModel::deleteShift", "[ShiftModel]")
{
   shiftModel->addShift(&layoutforTest, "Test worker name in deleteShift test");
   shiftModel->deleteShift(0);
   REQUIRE(workerWidgetVec.size() == 0);
}