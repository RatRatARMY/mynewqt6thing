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
        home.ui
        sdl3game1_desc.cpp
        sdl3game1_desc.hpp
        sdl3game1_desc.ui
        sdl3game2_desc.cpp
        sdl3game2_desc.hpp
        sdl3game2_desc.ui
        sdl3game3_desc.cpp
        sdl3game3_desc.hpp
        sdl3game3_desc.ui
        sdl3game4_desc.cpp
        sdl3game4_desc.hpp
        sdl3game4_desc.ui
        assets/common.qrc
)
target_link_libraries(mynewqt6thing
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

