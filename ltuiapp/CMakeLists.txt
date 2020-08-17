cmake_minimum_required(VERSION 3.11)

project(ltui_app
    LANGUAGES
        CXX
)

add_executable(${PROJECT_NAME}
  src/main.cpp
  src/home_view.cpp
  src/router.cpp
  src/view.cpp
  src/new_entry_view.cpp
  src/screen_service.cpp
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
    project_options
    ltui_crosscutting
    ltui_domain
    ltui_data
    ftxui_extended
    ftxui::dom
    ftxui::component
)

add_subdirectory(test)
