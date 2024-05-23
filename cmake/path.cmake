include(cmake/paths_to_cmake/header_files_paths/h_widgets_paths.cmake)
include(cmake/paths_to_cmake/header_files_paths/h_controllers_paths.cmake)
include(cmake/paths_to_cmake/header_files_paths/h_models_paths.cmake)

set(APP_HEADERS
    ../include/mainwindow.hpp  
    ../include/dependencymanager.hpp
    ../include/depmanagerhelpers/dependencyshiftmanager.hpp  
    ../include/depmanagerhelpers/dependencyworkermanager.hpp

    ${H_WIDGETS_PATHS}
    ${H_CONTROLLERS_PATHS}
    ${H_MODELS_PATHS}
)

include(cmake/paths_to_cmake/source_files_paths/s_widgets_paths.cmake)
include(cmake/paths_to_cmake/source_files_paths/s_controllers_paths.cmake)
include(cmake/paths_to_cmake/source_files_paths/s_models_paths.cmake)

set(APP_SOURCES
    ../src/mainwindow.cpp
    ../src/dependencymanager.cpp
    ../src/depmanagerhelpers/dependencyshiftmanager.cpp
    ../src/depmanagerhelpers/dependencyworkermanager.cpp

    ${S_WIDGETS_PATHS}
    ${S_CONTROLLERS_PATHS}
    ${S_MODELS_PATHS}
)

set(COMMON_SOURCES
    ${APP_SOURCES}
    ${APP_HEADERS}
)

set(APP_SOURCES_TEST 
  ../test/test_datamodel.cc
  ../test/test_shiftmodel.cc
  ../test/test_workermodel.cc
)