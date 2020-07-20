cmake_minimum_required(VERSION 3.5)

project(ltui_data_test
  LANGUAGES
    CXX
)

set(insert_instance_written ${PROJECT_NAME}_insert_instance_written)

add_executable(${insert_instance_written}
  ./insert_instance_written.cpp
)

target_link_libraries(${insert_instance_written}
  PUBLIC
    ltui_domain
    ltui_data
  PRIVATE
    project_options
)

add_test(
  NAME ${insert_instance_written}
  COMMAND $<TARGET_FILE:${insert_instance_written}>
)

