cmake_minimum_required(VERSION 3.0)
project(main.exe)
include_directories( ${CMAKE_SOURCE_DIR}/../include )


# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)
# set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

SET(CMAKE_CXX_FLAGS  "-g")

# find_package(Qt5 COMPONENTS Core REQUIRED)
# get_target_property(QtCore_location Qt5::Core LOCATION)

# find_package(Qt5 COMPONENTS Widgets REQUIRED)



#including directories did NOT WORK
# include_directories(
#     ${PROJECT_SOURCE_DIR}/run/
#     ${PROJECT_SOURCE_DIR}/hardware/
#     ${PROJECT_SOURCE_DIR}/os/
# )
# file(GLOB all_SRCS
#     "${PROJECT_SOURCE_DIR}/run/*.cpp"
#     "${PROJECT_SOURCE_DIR}/hardware/*.h"
#     "${PROJECT_SOURCE_DIR}/hardware/*.cpp"
#     "${PROJECT_SOURCE_DIR}/os/*.h"
#     "${PROJECT_SOURCE_DIR}/os/*.cpp"
# )


set (SOURCE
    ../include/int.h
    ../include/bit.h
    ../include/cpu.h
    ../include/register.h
    ../include/ram.h
    ../include/ram8.h
    ../include/ram64.h
    ../include/ram512.h
    ../include/ram4k.h
    ../include/pc.h
    ../include/hardware.h
    ../include/computer.h
    ../include/controller.h
    ../include/os.h
    ../include/process.h

    run/main.cpp
    hardware/int.cpp
    hardware/bit.cpp
    hardware/cpu.cpp
    hardware/register.cpp
    hardware/ram.cpp
    hardware/ram8.cpp
    hardware/ram64.cpp
    hardware/ram512.cpp
    hardware/ram4k.cpp
    hardware/pc.cpp
    hardware/hardware.cpp
    hardware/computer.cpp
    hardware/controller.cpp

    os/os.cpp
    os/process.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE})



# target_link_libraries(${PROJECT_NAME} Qt5::Widgets)