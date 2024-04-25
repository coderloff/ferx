cmake_minimum_required(VERSION 3.22)
project(imgui)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/imgui")

add_library(imgui)
target_sources(imgui PRIVATE 
"${SRC_DIR}/imgui.cpp"
"${SRC_DIR}/imgui_demo.cpp"
"${SRC_DIR}/imgui_draw.cpp"
"${SRC_DIR}/imgui_tables.cpp"
"${SRC_DIR}/imgui_widgets.cpp"
"${SRC_DIR}/backends/imgui_impl_glfw.cpp"
"${SRC_DIR}/backends/imgui_impl_opengl3.cpp"
)

target_include_directories(imgui PUBLIC "${SRC_DIR}")
target_include_directories(imgui PUBLIC "${SRC_DIR}/backends")

target_link_libraries(imgui PUBLIC glfw glad)
