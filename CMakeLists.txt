# Set minimum CMake version
cmake_minimum_required(VERSION 3.22)

# Declare project
project(ferx)

# Define C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define variables of directory paths
set(THIRDPARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty)

# Add third party libraries
add_subdirectory(${THIRDPARTY_DIR}/glad)
add_subdirectory(${THIRDPARTY_DIR}/glfw)
add_subdirectory(${THIRDPARTY_DIR}/glm)
add_subdirectory(${THIRDPARTY_DIR}/imgui)
add_subdirectory(${THIRDPARTY_DIR}/stb)

# Add engine and editor
add_subdirectory(engine)
add_subdirectory(editor)

# Create .desktop file for linux
if(UNIX)
	set(DESKTOP_FILE "${EDITOR_RESOURCES_DIR}/ferx.desktop")
	set(ICON_FILE "${ENGINE_RESOURCES_DIR}/icons/icon.png")

	include(GNUInstallDirs)

	install(FILES ${DESKTOP_FILE}
	        DESTINATION ${CMAKE_INSTALL_DATADIR}/applications
	)

	install(FILES ${ICON_FILE}
	        DESTINATION ${CMAKE_INSTALL_DATADIR}/icons/hicolor/256x256/apps
	        RENAME ferx.png
	)
endif(UNIX)
