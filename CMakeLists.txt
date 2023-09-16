cmake_minimum_required(VERSION 3.20)
project(SmartWorkPlan VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/path.cmake)
include(cmake/setup_catch2.cmake)
include(cmake/basic_configuration_functions.cmake)

add_executable(app
    src/main.cpp
    ${COMMON_SOURCES}
)

setup_target(app) 

add_executable(app-t 
  test/test_main.cc
  ${APP_SOURCES_TEST}
  ${COMMON_SOURCES}
)

target_link_libraries(app-t PRIVATE Catch2::Catch2)
setup_target(app-t)