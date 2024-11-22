# Set minimum CMake version
cmake_minimum_required(VERSION 3.22)

# Declare project
project(engine)

# Define variables of source files and include directories
set(CORE_INCLUDES core)
set(INPUT_INCLUDES core/input)
file(GLOB_RECURSE CORE_SOURCES "${CORE_INCLUDES}/*.cpp")
file(GLOB_RECURSE INPUT_SOURCES "${INPUT_INCLUDES}/*.cpp")

set(RENDERING_INCLUDES rendering)
file(GLOB_RECURSE RENDERING_SOURCES "${RENDERING_INCLUDES}/*.cpp")

set(SCENE_INCLUDES scene)
set(COMPONENTS_INCLUDES scene/components)
file(GLOB SCENE_SOURCES "${SCENE_INCLUDES}/*.cpp")
file(GLOB COMPONENTS_SOURCES "${COMPONENTS_INCLUDES}/*.cpp")

set(UI_INCLUDES ui)
file(GLOB UI_SOURCES "${UI_INCLUDES}/*.cpp")

set(ENGINE_RESOURCES_DIR resources)

# Build engine as library
add_library(${PROJECT_NAME})

# Add resources folder
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    file(COPY ${ENGINE_RESOURCES_DIR} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    target_compile_definitions(${PROJECT_NAME} PUBLIC ENGINE_RESOURCES_PATH="${CMAKE_CURRENT_BINARY_DIR}/resources/")
else()
    target_compile_definitions(${PROJECT_NAME} PUBLIC ENGINE_RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/")
endif()

# Link sources, include directories, and third party libraries
target_include_directories(${PROJECT_NAME} PUBLIC
        ${CORE_INCLUDES} ${INPUT_INCLUDES}
        ${RENDERING_INCLUDES}
        ${SCENE_INCLUDES} ${COMPONENTS_INCLUDES}
        ${UI_INCLUDES})
target_sources(${PROJECT_NAME} PRIVATE
        ${CORE_SOURCES} ${INPUT_SOURCES}
        ${RENDERING_SOURCES}
        ${SCENE_SOURCES} ${COMPONENTS_SOURCES}
        ${UI_SOURCES})
target_link_libraries(${PROJECT_NAME} glfw glad glm imgui stb)
