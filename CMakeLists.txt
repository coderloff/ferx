cmake_minimum_required(VERSION 3.22)
project(ferx)
set(CMAKE_CXX_STANDARD 17)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(THIRDPARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party)

file(GLOB_RECURSE SOURCES CONFIG_DEPENDS "${SRC_DIR}/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

if(GLEW_FOUND)
	include_directories(${GLEW_INCLUDE_DIRS})
	link_libraries(${GLEW_LIBRARIES})
endif()

add_subdirectory(${THIRDPARTY_DIR}/imgui)

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} glfw GLEW imgui)
