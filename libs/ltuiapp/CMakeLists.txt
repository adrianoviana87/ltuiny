cmake_minimum_required(VERSION 3.11)

project(ltui_app
    LANGUAGES
        CXX
)

add_executable(${PROJECT_NAME} "")
target_sources(
  ${PROJECT_NAME}
  PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/src/home_view.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/new_entry_view.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/router.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/screen_service.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/view.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/app_settings.hpp
  ${CMAKE_CURRENT_LIST_DIR}/src/entry_dto.hpp
  ${CMAKE_CURRENT_LIST_DIR}/src/home_view.hpp
  ${CMAKE_CURRENT_LIST_DIR}/src/input.hpp
  ${CMAKE_CURRENT_LIST_DIR}/src/new_entry_view.hpp
  ${CMAKE_CURRENT_LIST_DIR}/src/router.hpp
  ${CMAKE_CURRENT_LIST_DIR}/src/screen_service.hpp
  ${CMAKE_CURRENT_LIST_DIR}/src/view.hpp
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    project_options
  PUBLIC
    ltui_crosscutting
    ltui_domain
    ltui_data
    ftxui_extended
    ftxui::dom
    ftxui::component
)

