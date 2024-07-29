project(engine)

set(ENGINE_SOURCE_DIR src)
set(ENGINE_INCLUDE_DIR include)

file(GLOB_RECURSE ENGINE_SOURCES ${ENGINE_SOURCE_DIR}/*.cpp)

add_library(${PROJECT_NAME})

target_compile_definitions(${PROJECT_NAME} PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/") # This is useful to get an ASSETS_PATH in your IDE during development but you should comment this if you compile a release version and uncomment the next line
#target_compile_definitions(${PROJECT_NAME} PUBLIC RESOURCES_PATH="./resources/") # Uncomment this line to setup the ASSETS_PATH macro to the final assets directory when you share the game

target_sources(${PROJECT_NAME} PRIVATE ${ENGINE_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${ENGINE_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} glfw glad glm imgui)
