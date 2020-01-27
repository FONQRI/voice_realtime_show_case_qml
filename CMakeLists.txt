cmake_minimum_required(VERSION 2.8.12)

project(voice_realtime_show_case_qml LANGUAGES CXX)
set(CMAKE_PREFIX_PATH "$ENV{QTDIR}")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};/home/fonqri/Qt5.14.0/5.14.0/gcc_64/lib/cmake")

set (CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++14 -D__STRICT_ANSI__")

#seting file pathes
file(GLOB audio_headers ./src/audio/*.h)
file(GLOB audio_cpp ./src/audio/*.cpp)
file(GLOB audio_hpp ./src/audio/*.hpp)

file(GLOB gui_headers ./src/gui/*.h)
file(GLOB gui_cpp ./src/gui/*.cpp)
file(GLOB gui_hpp ./src/gui/*.hpp)



#find pakages
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Charts REQUIRED)
find_package(Qt5Quick REQUIRED)
find_package(Qt5Multimedia REQUIRED)

#find_package(Qt5 COMPONENTS Core Quick Charts Multimedia REQUIRED)

#includes
include_directories(
    ./src
    ${Qt5Core_INCLUDE_DIRS}
    ${Qt5Sql_INCLUDE_DIRS}
    ${Qt5Charts_INCLUDE_DIRS}
    ${Qt5Gui_INCLUDE_DIRS}
    ${Qt5Quick_INCLUDE_DIRS}
    ${Qt5Multimedia_INCLUDE_DIRS}
    ${QT_INCLUDE_DIR}
    )
#include( ${QT_USE_FILE})

#library
add_library(audio_core
  ${audio_headers}
  ${audio_cpp}
  ${audio_hpp}
  )

target_link_libraries(audio_core
  Qt5::Core
  Qt5::Quick
  Qt5::Charts
  Qt5::Multimedia

  )



add_library(gui_core
  ${gui_headers}
  ${gui_cpp}
  ${gui_hpp}
)


target_link_libraries(gui_core
  Qt5::Core
  Qt5::Quick
  Qt5::Charts

  )


add_executable(${PROJECT_NAME} "main.cpp" "qml.qrc")

target_link_libraries(${PROJECT_NAME}
  Qt5::Core
  Qt5::Quick
  Qt5::Charts
  Qt5::Multimedia
  gui_core
  audio_core

  )
