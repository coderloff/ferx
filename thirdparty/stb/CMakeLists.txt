cmake_minimum_required(VERSION 3.22)

project(stb)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_library(stb)

target_include_directories(stb PUBLIC include)

target_sources(stb PRIVATE ${SOURCES})