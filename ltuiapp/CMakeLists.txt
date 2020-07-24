cmake_minimum_required(VERSION 3.5)

find_package(ftxui REQUIRED)
find_package(Threads)

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
  src/button.cpp
  inc/list.hpp
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
    project_options
    ltui_crosscutting
    ltui_domain
    ltui_data
    ftxui::dom
    ftxui::component
)

add_subdirectory(test)
