cmake_minimum_required(VERSION 4.2)
project(mynewqt6thing)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(mynewqt6thing main.cpp
        login.cpp
        login.hpp
        login.ui
        register.cpp
        register.hpp
        register.ui
        home.cpp
        home.hpp
        home.ui)
target_link_libraries(mynewqt6thing
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

