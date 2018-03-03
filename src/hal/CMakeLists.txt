# Specify the minimum version of cmake.
cmake_minimum_required(VERSION 3.0)

project(hal)

set(PROJECT_NAME hal)
include_directories("../")

file(GLOB header_list "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")

if(${TARGET_PLATFROM} STREQUAL rpi)
    file(GLOB source_list "${CMAKE_CURRENT_SOURCE_DIR}/rpi/*.cpp")
elseif(${TARGET_PLATFROM} STREQUAL virtualBoard)
    file(GLOB source_list "${CMAKE_CURRENT_SOURCE_DIR}/virtualBoard/*.cpp")
endif()


add_library(${PROJECT_NAME} ${source_list})

target_include_directories(
        ${PROJECT_NAME} PUBLIC
        # Headers used from source/build location:
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        # Headers used from the installed location:
        "$<INSTALL_INTERFACE:include>"
)

install(TARGETS ${PROJECT_NAME} DESTINATION lib OPTIONAL)
install(FILES ${header_list} DESTINATION include OPTIONAL)

if(BUILD_TESTS)
    #add_subdirectory(unit_tests)
endif()