cmake_minimum_required(VERSION 3.5)

find_package(ftxui REQUIRED)
find_package(Threads)

project(ftxui_extended
    LANGUAGES
        CXX
)

add_library(${PROJECT_NAME}
  src/button.cpp
  inc/button.hpp
  inc/list.hpp
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
    project_options
    ftxui::dom
    ftxui::component
)

