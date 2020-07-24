cmake_minimum_required(VERSION 3.5)

project(ltui)

include(cmake/CompilerWarnings.cmake)
include(cmake/StandardProjectSettings.cmake)
include(cmake/PreventInSourceBuilds.cmake)

add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

enable_testing()

add_subdirectory(crosscutting)
add_subdirectory(domain)
add_subdirectory(data)
add_subdirectory(ltuiapp)
