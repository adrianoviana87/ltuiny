cmake_minimum_required(VERSION 3.5)

project(ltui_app_test
  LANGUAGES
    CXX
)

set(input_test ${PROJECT_NAME}_input_test)

add_executable(${input_test}
  ./input_test.cpp
)

target_link_libraries(${input_test}
  PRIVATE
    project_options
)

add_test(
  NAME ${input_test}
  COMMAND $<TARGET_FILE:${input_test}>
)


