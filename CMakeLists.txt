cmake_minimum_required(VERSION 3.22)
project(project2)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(CURL REQUIRED)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(project2 main.cpp QuoteGenerator.cpp QuoteGenerator.h)
include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(project2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        ${CURL_LIBRARIES}
        )


