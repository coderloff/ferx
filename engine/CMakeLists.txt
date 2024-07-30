project(engine)

set(ENGINE_SOURCE_DIR src)
set(ENGINE_INCLUDE_DIR include)

file(GLOB_RECURSE ENGINE_SOURCES ${ENGINE_SOURCE_DIR}/*.cpp)

add_library(${PROJECT_NAME})

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(${PROJECT_NAME} PUBLIC RESOURCES_PATH="./resources/")
else()
    target_compile_definitions(${PROJECT_NAME} PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/")
endif()

target_sources(${PROJECT_NAME} PRIVATE ${ENGINE_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${ENGINE_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} glfw glad glm imgui)
