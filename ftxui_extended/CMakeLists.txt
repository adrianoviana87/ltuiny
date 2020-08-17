cmake_minimum_required(VERSION 3.11)

# find_package(ftxui REQUIRED)
# find_package(Threads)

project(ftxui_extended
    LANGUAGES
        CXX
)

add_library(${PROJECT_NAME}
  src/button.cpp
  src/maskinputbase.cpp
  src/dateinput.cpp
  src/moneyinput.cpp
  inc/button.hpp
  inc/list.hpp
  inc/maskinputbase.hpp
  inc/dateinput.hpp
  inc/moneyinput.hpp
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
    project_options
    ftxui::dom
    ftxui::component
)

