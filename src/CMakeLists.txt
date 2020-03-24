cmake_minimum_required(VERSION 2.8)
project(calculator)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})

add_executable(${PROJECT_NAME} calculator.c)
target_link_libraries(${PROJECT_NAME} ${GTK3_LIBRARIES})
