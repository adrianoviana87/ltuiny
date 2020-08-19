cmake_minimum_required(VERSION 3.11)

project(ltui_domain
  LANGUAGES
    CXX
)

add_library(${PROJECT_NAME} "")
target_sources(
  ${PROJECT_NAME}
  PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/src/domain_operator_overloading.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/ledger_account.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/ledger_amount.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/ledger_entry.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/ledger_entry_service.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/ledger_transaction.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/domain_operator_overloading.hpp
  ${CMAKE_CURRENT_LIST_DIR}/src/ledger_account.hpp
  ${CMAKE_CURRENT_LIST_DIR}/src/ledger_amount.hpp
  ${CMAKE_CURRENT_LIST_DIR}/src/ledger_entry.hpp
  ${CMAKE_CURRENT_LIST_DIR}/src/ledger_entry_repository.hpp
  ${CMAKE_CURRENT_LIST_DIR}/src/ledger_entry_service.hpp
  ${CMAKE_CURRENT_LIST_DIR}/src/ledger_transaction.hpp
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/include/domain.hpp
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    project_options
  PUBLIC
    ltui_crosscutting
)

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/include
)

add_subdirectory(test)
