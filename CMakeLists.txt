cmake_minimum_required(VERSION 3.9)

project(Calendar)

# TODO: debug flags?
# TODO: -Wall -pedantic

# TODO: add cmake to linked list project
# add_library(linkedlist src/linkedlist/linkedlist.c)

# GTK+ files/flags
find_package(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})

# add the project header files to path
include_directories(include)

add_executable(calendar src/main.c src/gui.c)

# link the executable to the gtk libraries
target_link_libraries(calendar ${GTK3_LIBRARIES})

