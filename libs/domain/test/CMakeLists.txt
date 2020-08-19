cmake_minimum_required(VERSION 3.11)

project(ltui_domain_test
  LANGUAGES
    CXX
)

set(ledger_entry_stream_output_operator ${PROJECT_NAME}_ledger_entry_stream_output_operator)

add_executable(${ledger_entry_stream_output_operator}
  ./ledger_entry_stream_output_operator.cpp
)

target_link_libraries(${ledger_entry_stream_output_operator}
  PUBLIC
    ltui_domain
    ltui_crosscutting
  PRIVATE
    project_options
)

add_test(
  NAME ${ledger_entry_stream_output_operator}
  COMMAND $<TARGET_FILE:${ledger_entry_stream_output_operator}>
)

