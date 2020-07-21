cmake_minimum_required(VERSION 3.5)

project(ltui_app
    LANGUAGES
        CXX
)

add_executable(${PROJECT_NAME}
  src/view.cpp
  src/home_view.cpp
  src/add_invoice_view.cpp
  src/router.cpp
  src/main.cpp
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
    ltui_domain
    ltui_data
  PRIVATE
    project_options
)

