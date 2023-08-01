cmake_minimum_required(VERSION 3.20)
project(SmartWorkPlan VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets PrintSupport)

set(APP_SOURCES
    src/mainwindow.cpp

    src/widgets/workersremovaldialog.cpp
    src/widgets/calendarfieldwidget.cpp
    src/widgets/calendarwidget.cpp
    src/widgets/workerwidget.cpp
    src/widgets/workerwizard.cpp
    src/widgets/shiftwizard.cpp

    src/controllers/workercontroller.cpp
    src/controllers/printcontroller.cpp
    src/controllers/shiftcontroller.cpp

    src/models/workerdatamodel.cpp
    src/models/shiftdatamodel.cpp
    src/models/workermodel.cpp
    src/models/printmodel.cpp
    src/models/shiftmodel.cpp
)

set(APP_HEADERS
    include/mainwindow.hpp    

    include/widgets/workersremovaldialog.hpp
    include/widgets/calendarfieldwidget.hpp
    include/widgets/calendarwidget.hpp
    include/widgets/workerwidget.hpp
    include/widgets/workerwizard.hpp
    include/widgets/shiftwizard.hpp

    include/controllers/workercontroller.hpp
    include/controllers/printcontroller.hpp
    include/controllers/shiftcontroller.hpp

    include/models/workerdatamodel.hpp
    include/models/shiftdatamodel.hpp
    include/models/workermodel.hpp
    include/models/printmodel.hpp
    include/models/shiftmodel.hpp

)

add_executable(app
    src/main.cpp
    ${APP_SOURCES}
    ${APP_HEADERS}
)

set_target_properties(app PROPERTIES AUTOUIC_SEARCH_PATHS "./frontend")
target_link_libraries(app PUBLIC Qt6::Widgets Qt6::PrintSupport)