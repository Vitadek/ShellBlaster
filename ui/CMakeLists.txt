cmake_minimum_required (VERSION 3.11)

#---FTX Stuff----
include (FetchContent)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v5.0.0
  )

FetchContent_GetProperties(ftxui)
if (NOT ftx_POPULATED)
    FetchContent_Populate(ftxui)
    add_subdirectory(${ftxui_SOURCE_DIR}${ftx_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

#------------


project(ShellBlaster
  LANGUAGES CXX
  VERSION 1.0.0
)

add_executable(ShellBlaster src/main.cpp)
target_include_directories (ShellBlaster PRIVATE src)

target_link_libraries(ShellBlaster
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
)
