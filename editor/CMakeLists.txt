project(editor)

set(NAME ferx)
set(EDITOR_SOURCE_DIR src)
set(EDITOR_INCLUDE_DIR include)
set(EDITOR_RESOURCES_DIR resources)

file(GLOB_RECURSE EDITOR_SOURCES ${EDITOR_SOURCE_DIR}/*.cpp)
file(COPY ${EDITOR_RESOURCES_DIR}/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(${NAME} ${EDITOR_SOURCES} ${EDITOR_HEADERS})

target_sources(${NAME} PRIVATE ${EDITOR_SOURCES})
target_include_directories(${NAME} PRIVATE ${EDITOR_INCLUDE_DIR})

target_link_libraries(${NAME} engine)
