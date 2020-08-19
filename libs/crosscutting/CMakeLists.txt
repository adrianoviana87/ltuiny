cmake_minimum_required(VERSION 3.11)

project(ltui_crosscutting
  LANGUAGES
    CXX
)

add_library(${PROJECT_NAME} "")
target_sources(
  ${PROJECT_NAME}
  PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/src/noexcept.hpp
  ${CMAKE_CURRENT_LIST_DIR}/src/string-utils.hpp
  ${CMAKE_CURRENT_LIST_DIR}/src/string-utils.cpp
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/include/crosscutting.hpp
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    project_options
)

target_include_directories(${PROJECT_NAME}
                           PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)

