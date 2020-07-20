cmake_minimum_required(VERSION 3.5)

project(ltui_domain
  LANGUAGES
    CXX
)

add_library(${PROJECT_NAME}
  src/ledger_amount.cpp
  src/ledger_account.cpp
  src/ledger_transaction.cpp
  src/ledger_entry.cpp
  src/ledger_entry_service.cpp
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    project_options
)

add_library(test)
