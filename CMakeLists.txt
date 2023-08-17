cmake_minimum_required(VERSION 3.10)

project(orz)

add_definitions(-D_GNU_SOURCE)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)

add_library(orz SHARED 
    source/orz_date.c
)

target_include_directories(orz
    PRIVATE
    source/include
)


install(TARGETS orz)
