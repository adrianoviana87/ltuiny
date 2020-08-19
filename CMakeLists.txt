cmake_minimum_required(VERSION 3.11)

project(ltui)

include(cmake/CompilerWarnings.cmake)
include(cmake/StandardProjectSettings.cmake)
include(cmake/PreventInSourceBuilds.cmake)

add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

enable_testing()

include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
)

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

add_subdirectory(libs/crosscutting)
add_subdirectory(libs/domain)
add_subdirectory(libs/data)
add_subdirectory(libs/ftxui_extended)
add_subdirectory(libs/ltuiapp)
