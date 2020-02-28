cmake_minimum_required(VERSION 3.0)
project(main.exe)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

SET(CMAKE_CXX_FLAGS  "-g")

find_package(Qt5 COMPONENTS Core REQUIRED)
get_target_property(QtCore_location Qt5::Core LOCATION)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(SOURCE ../source/main.cpp
    ../source/int.h
    ../source/int.cpp
    ../source/bit.h
    ../source/bit.cpp
    ../source/cpu.h
    ../source/cpu.cpp
    ../source/register.h
    ../source/register.cpp
    ../source/ram.h
    ../source/ram.cpp
    ../source/ram8.h
    ../source/ram8.cpp
    ../source/ram64.h
    ../source/ram64.cpp
    ../source/pc.h
    ../source/pc.cpp
    ../source/hardware.h
    ../source/hardware.cpp
    ../source/computer.h
    ../source/computer.cpp
    ../source/controller.h
    ../source/controller.cpp
    ../source/os.h
    ../source/os.cpp
)
add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)