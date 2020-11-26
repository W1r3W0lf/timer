project(timer C)

cmake_minimum_required(VERSION 3.14)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

# Cmake doesn't recommend this. ... But I don't care
file(GLOB timer_SRC
    "src/*.h"
    "src/*.c"
)

add_executable(timer ${timer_SRC})

target_link_libraries(timer ${GTK3_LIBRARIES})
