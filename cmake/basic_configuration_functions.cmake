find_package(Qt6 REQUIRED COMPONENTS Widgets PrintSupport)

function(setup_target TARGET_NAME)
    target_link_libraries(${TARGET_NAME} PUBLIC Qt6::Widgets Qt6::PrintSupport)
    set_target_properties(${TARGET_NAME} PROPERTIES AUTOUIC_SEARCH_PATHS "./frontend")
endfunction()
