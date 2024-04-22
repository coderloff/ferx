cmake_minimum_required(VERSION 3.22)
project(ferx)
set(CMAKE_CXX_STANDARD 17)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(THIRDPARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty)

file(GLOB_RECURSE SOURCES CONFIG_DEPENDS "${SRC_DIR}/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(${THIRDPARTY_DIR}/glad)
add_subdirectory(${THIRDPARTY_DIR}/glfw)
add_subdirectory(${THIRDPARTY_DIR}/imgui)

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} glfw glad imgui)
