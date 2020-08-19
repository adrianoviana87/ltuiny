cmake_minimum_required(VERSION 3.11)

project(ftxui_extended
    LANGUAGES
        CXX
)

add_library(${PROJECT_NAME} "")

target_sources(
  ${PROJECT_NAME}
  PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/src/button.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/dateinput.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/maskinputbase.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/moneyinput.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/button.hpp
  ${CMAKE_CURRENT_LIST_DIR}/src/dateinput.hpp
  ${CMAKE_CURRENT_LIST_DIR}/src/list.hpp
  ${CMAKE_CURRENT_LIST_DIR}/src/maskinputbase.hpp
  ${CMAKE_CURRENT_LIST_DIR}/src/moneyinput.hpp
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/include/ftxui-extended.hpp
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    project_options
  PUBLIC
    ltui_crosscutting
    ftxui::dom
    ftxui::component
)

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/include
)

