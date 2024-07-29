cmake_minimum_required(VERSION 3.22)

# Declare project
project(ferx)

# Define C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define variables of directory paths
set(THIRDPARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty)

# Add thirdparty libraries
add_subdirectory(${THIRDPARTY_DIR}/glad)
add_subdirectory(${THIRDPARTY_DIR}/glfw)
add_subdirectory(${THIRDPARTY_DIR}/glm)
add_subdirectory(${THIRDPARTY_DIR}/imgui)

# Add engine and editor
add_subdirectory(engine)
add_subdirectory(editor)
