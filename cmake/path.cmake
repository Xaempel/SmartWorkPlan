set(APP_HEADERS
    ../include/mainwindow.hpp    

    ../include/widgets/workersremovaldialog.hpp
    ../include/widgets/calendarfieldwidget.hpp
    ../include/widgets/calendarwidget.hpp
    ../include/widgets/workerwidget.hpp
    ../include/widgets/workerwizard.hpp
    ../include/widgets/shiftwizard.hpp

    ../include/controllers/workercontroller.hpp
    ../include/controllers/printcontroller.hpp
    ../include/controllers/shiftcontroller.hpp

    ../include/models/workerdatamodel.hpp
    ../include/models/shiftdatamodel.hpp
    ../include/models/workermodel.hpp
    ../include/models/printmodel.hpp
    ../include/models/shiftmodel.hpp
)

set(APP_SOURCES
    ../src/mainwindow.cpp

    ../src/widgets/workersremovaldialog.cpp
    ../src/widgets/calendarfieldwidget.cpp
    ../src/widgets/calendarwidget.cpp
    ../src/widgets/workerwidget.cpp
    ../src/widgets/workerwizard.cpp
    ../src/widgets/shiftwizard.cpp

    ../src/controllers/workercontroller.cpp
    ../src/controllers/printcontroller.cpp
    ../src/controllers/shiftcontroller.cpp

    ../src/models/workerdatamodel.cpp
    ../src/models/shiftdatamodel.cpp
    ../src/models/workermodel.cpp
    ../src/models/printmodel.cpp
    ../src/models/shiftmodel.cpp
)

set(COMMON_SOURCES
    ${APP_SOURCES}
    ${APP_HEADERS}
)

set(APP_SOURCES_TEST 
  ../test/test_workerdatamodel.cc 
)