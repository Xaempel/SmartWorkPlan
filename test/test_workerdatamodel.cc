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

#include "../include/models/workerdatamodel.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Add worker Test", "[WorkerDataMode]")
{
   WorkerDataModel workerDataModel;
   REQUIRE(workerDataModel.saveWorkerLists("John", "Doe") == true);
   QFile::remove("data.json");
}

TEST_CASE("Delete worker from list Test", "[WorkerDataMode]")
{
   WorkerDataModel workerDataModel;
   workerDataModel.saveWorkerLists("John", "Doe");
   workerDataModel.removeWorkerFromLists(1);
   REQUIRE(workerDataModel.loadWorkerLists().size() == 0);
   QFile::remove("data.json");
}

TEST_CASE("Load worker lists Test", "[WorkerDataMode]")
{
   WorkerDataModel workerDataModel;
   QStringList TestStringList {};

   workerDataModel.saveWorkerLists("John", "Doe");

   auto LoadWorkerLists {workerDataModel.loadWorkerLists()};
   TestStringList = LoadWorkerLists;

   REQUIRE(TestStringList == LoadWorkerLists);
   QFile::remove("data.json");
}