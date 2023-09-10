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

#include "../include/models/datamodel.hpp"

#include <QString>
#include <catch2/catch.hpp>

struct DataModelTestData {
   DataModel dataModel {};
};

namespace usefulFunctionsforTests {

   void clearTrash()
   {
      QFile::remove("data.json");
      QFile::remove("TestFile");
      QFile::remove("Str save file");
   }

}

TEST_CASE_METHOD(DataModelTestData, "DataModel::save", "[DataModel]")
{
   SECTION("save int")
   {
      int testInttoSave {2589};

      SECTION("File to save data is default")
      {
         bool check = dataModel.save(std::nullopt, "Test Data", testInttoSave, 1234, 136);
         REQUIRE(check == true);
      }
      SECTION("File to save data have name")
      {
         bool check = dataModel.save("TestFile", "Test Data", testInttoSave, 1234, 136);
         REQUIRE(check == true);
      }
   }

   SECTION("save string")
   {
      QString testStr {"im test string"};
      SECTION("File to save data is default")
      {
         bool check = dataModel.save(std::nullopt, "Test Data Str section no name", testStr, "john", "jeff");
         REQUIRE(check == true);
      }
      SECTION("File to save data have name")
      {
         bool check = dataModel.save("Str save file", "Test Data Str section no name", testStr, "john2", "jeff2");
         REQUIRE(check == true);
      }
   }
   usefulFunctionsforTests::clearTrash();
}

TEST_CASE_METHOD(DataModelTestData, "DataModel::load", "[DataModel]")
{
   QVariantList listHaveLoadValue {};
   SECTION("load int")
   {
      const QVariantList listHaveSaveValue {263, 1256, 125};
      dataModel.save(std::nullopt, "int section", 263, 1256, 125);
      dataModel.load("data.json", "int section", listHaveLoadValue);
      REQUIRE(listHaveLoadValue == listHaveSaveValue);
      listHaveLoadValue.clear();
   }

   SECTION("load str")
   {
      const QVariantList listHaveSaveValue {"Adam", "Jan", "Kowalski", "im name!!!"};
      dataModel.save(std::nullopt, "str section", "Adam", "Jan", "Kowalski", "im name!!!");
      dataModel.load("data.json", "str section", listHaveLoadValue);
      REQUIRE(listHaveLoadValue == listHaveSaveValue);
      listHaveLoadValue.clear();
   }

   SECTION("load different data")
   {
      const QVariantList listHaveSaveValue {"im str", 212, 0.24, "hello test", "other str", 215};
      dataModel.save(std::nullopt, "different section", "im str", 212, 0.24, "hello test", "other str", 215);
      dataModel.load("data.json", "different section", listHaveLoadValue);
      REQUIRE(listHaveLoadValue == listHaveSaveValue);
      listHaveLoadValue.clear();
   }
   usefulFunctionsforTests::clearTrash();
}

TEST_CASE_METHOD(DataModelTestData, "DataModel::deleteDatafromFile", "[DataModel]")
{
   QVariantList listHaveSaveValue {125, 6126, 12516, "john"};
   QVariantList listHaveLoadValue {};

   dataModel.save(std::nullopt, "test section", 125, 6126, 12516, "john");
   dataModel.load("data.json", "test section", listHaveLoadValue);
   dataModel.deleteDatafromFile("data.json", "test section", 1);
   dataModel.load("data.json", "test section", listHaveLoadValue);
   REQUIRE(listHaveLoadValue != listHaveSaveValue);
   usefulFunctionsforTests::clearTrash();
}