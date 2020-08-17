cmake_minimum_required(VERSION 3.11)

project(ltui_crosscutting
  LANGUAGES
    CXX
)

add_library(${PROJECT_NAME}
  inc/string-utils.hpp
  src/string-utils.cpp
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    project_options
)
