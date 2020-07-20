cmake_minimum_required(VERSION 3.5)

project(ltui_data
  LANGUAGES
    CXX
)

add_library(${PROJECT_NAME}
  src/ledger_entry_file_repository.cpp
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
    ltui_domain
  PRIVATE
    project_options
)

add_subdirectory(test)

