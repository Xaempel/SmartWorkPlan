cmake_minimum_required(VERSION 3.20)
project(SmartWorkPlan VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets PrintSupport)

include(cmake/path.cmake)

function(setup_target TARGET_NAME)
    target_link_libraries(${TARGET_NAME} PUBLIC Qt6::Widgets Qt6::PrintSupport)
    set_target_properties(${TARGET_NAME} PROPERTIES AUTOUIC_SEARCH_PATHS "./frontend")
endfunction()

set(COMMON_SOURCES
    ${APP_SOURCES}
    ${APP_HEADERS}
)

add_executable(app
    src/main.cpp
    ${COMMON_SOURCES}
)

set(CATCH2_DIR ${CMAKE_BINARY_DIR}/external/catch2)
include(FetchContent)

FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.7  
)

FetchContent_GetProperties(catch2)
if(NOT catch2_POPULATED)
  FetchContent_Populate(catch2)
  add_subdirectory(${catch2_SOURCE_DIR} ${catch2_BINARY_DIR})
endif()

add_executable(app-t 
  test/test_main.cc
  ${APP_SOURCES_TEST}
  ${COMMON_SOURCES}
)

setup_target(app) 
setup_target(app-t)
target_link_libraries(app-t PRIVATE Catch2::Catch2)