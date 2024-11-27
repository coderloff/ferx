cmake_minimum_required(VERSION 3.22)

project(editor)

set(NAME ferx)
set(EDITOR_SOURCE_DIR src)
set(EDITOR_INCLUDE_DIR include)
set(EDITOR_RESOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/resources)
set(EDITOR_RESOURCES_DIR ${EDITOR_RESOURCES_DIR} PARENT_SCOPE)

file(GLOB_RECURSE EDITOR_SOURCES ${EDITOR_SOURCE_DIR}/*.cpp)

add_executable(${NAME})

# Add resources folder
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    file(COPY ${EDITOR_RESOURCES_DIR} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    target_compile_definitions(${NAME} PUBLIC EDITOR_RESOURCES_PATH="${CMAKE_CURRENT_BINARY_DIR}/resources/")
else()
    target_compile_definitions(${NAME} PUBLIC EDITOR_RESOURCES_PATH="${EDITOR_RESOURCES_DIR}/")
endif()

target_sources(${NAME} PRIVATE ${EDITOR_SOURCES})
target_include_directories(${NAME} PRIVATE ${EDITOR_INCLUDE_DIR})
target_link_libraries(${NAME} engine)
