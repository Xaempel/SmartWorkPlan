include(cmake/paths_to_cmake/header_files_paths/h_widgets_paths.cmake)
include(cmake/paths_to_cmake/header_files_paths/h_controllers_paths.cmake)
include(cmake/paths_to_cmake/header_files_paths/h_models_paths.cmake)
include(cmake/paths_to_cmake/header_files_paths/h_controllers_helpers.cmake)

set(APP_HEADERS
    include/MainWindow.hpp  
    include/DependencyManager.hpp
    include/DepedencyManagerHelpers/DependencyShiftManager.hpp
    include/DepedencyManagerHelpers/DependencyWorkerManager.hpp

    ${H_WIDGETS_PATHS}
    ${H_CONTROLLERS_PATHS}
    ${H_MODELS_PATHS}
    ${H_CONTROLLER_HELPERS}
)

include(cmake/paths_to_cmake/source_files_paths/s_widgets_paths.cmake)
include(cmake/paths_to_cmake/source_files_paths/s_controllers_paths.cmake)
include(cmake/paths_to_cmake/source_files_paths/s_models_paths.cmake)
include(cmake/paths_to_cmake/source_files_paths/s_controllers_helpers.cmake)

set(APP_SOURCES
    src/MainWindow.cpp
    src/DependencyManager.cpp
    src/DepedencyManagerHelpers/DependencyShiftManager.cpp
    src/DepedencyManagerHelpers/DependencyWorkerManager.cpp

    ${S_WIDGETS_PATHS}
    ${S_CONTROLLERS_PATHS}
    ${S_MODELS_PATHS}
    ${S_CONTROLLERS_HELPERS}
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