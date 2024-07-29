cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)

# Declare project
project(ferx)

# Define variables of directory paths
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/editor/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/editor/include)
set(THIRDPARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty)

# Add thirdparty libraries
add_subdirectory(${THIRDPARTY_DIR}/glad)
add_subdirectory(${THIRDPARTY_DIR}/glfw)
add_subdirectory(${THIRDPARTY_DIR}/glm)
add_subdirectory(${THIRDPARTY_DIR}/imgui)

# Define macros for the project sources
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${SOURCE_DIR}/*.cpp")
add_executable(${PROJECT_NAME})

target_compile_definitions(${PROJECT_NAME} PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/") # This is useful to get an ASSETS_PATH in your IDE during development but you should comment this if you compile a release version and uncomment the next line
#target_compile_definitions(${PROJECT_NAME} PUBLIC RESOURCES_PATH="./resources/") # Uncomment this line to setup the ASSETS_PATH macro to the final assets directory when you share the game

target_sources(${PROJECT_NAME} PRIVATE ${SOURCES} )
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad glm imgui)
