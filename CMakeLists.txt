cmake_minimum_required(VERSION 3.20)

project(SmartWorkPlan VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(app
    src/main.cpp

    include/mainwindow.hpp
    src/mainwindow.cpp
)

set_target_properties(app PROPERTIES AUTOUIC_SEARCH_PATHS "./frontend")

target_link_libraries(app PUBLIC Qt6::Widgets)