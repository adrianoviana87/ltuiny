cmake_minimum_required(VERSION 3.11)

project(ltui_data
  LANGUAGES
    CXX
)

add_library(${PROJECT_NAME} "")

target_sources(
  ${PROJECT_NAME}
  PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/src/ledger_entry_file_repository.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/ledger_entry_file_repository.hpp
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/include/data.hpp
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
    ltui_domain
  PRIVATE
    project_options
)

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/include
)

add_subdirectory(test)

