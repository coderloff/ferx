cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)

# Declare project
project(ferx)

# Define variables of directory paths
set(EDITOR_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/editor/src)
set(EDITOR_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/editor/include)
set(THIRDPARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty)

# Add thirdparty libraries
add_subdirectory(${THIRDPARTY_DIR}/glad)
add_subdirectory(${THIRDPARTY_DIR}/glfw)
add_subdirectory(${THIRDPARTY_DIR}/imgui)

# Define macros for the project sources
file(GLOB_RECURSE EDITOR_SOURCES CONFIGURE_DEPENDS "${EDITOR_SOURCE_DIR}/*.cpp")
add_executable(editor)

target_compile_definitions(editor PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/") # This is useful to get an ASSETS_PATH in your IDE during development but you should comment this if you compile a release version and uncomment the next line
#target_compile_definitions(editor PUBLIC RESOURCES_PATH="./resources/") # Uncomment this line to setup the ASSETS_PATH macro to the final assets directory when you share the game

target_sources(editor PRIVATE ${EDITOR_SOURCES} )
target_include_directories(editor PRIVATE ${EDITOR_INCLUDE_DIR})

target_link_libraries(editor PRIVATE glfw glad imgui)
