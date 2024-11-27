DEBUG_BUILD_DIR = build-debug
RELEASE_BUILD_DIR = build-release
EXECUTABLE_PATH = editor/ferx

LINUX_BUILD_DIR = /usr/local/lib/ferx
LINUX_INSTALL_FILE_PATH = InstallLinux.sh

RM += -r

all: debug

# Help
help:
	@echo "Usage: make <target>"
	@echo
	@echo "Targets:"
	@echo "  help                    	Show this help message"
	@echo "  install-dependencies    	Install project dependencies based on the detected Linux distribution"
	@echo "  install-ubuntu          	Install dependencies for Ubuntu/Debian-based systems"
	@echo "  install-fedora          	Install dependencies for Fedora/RHEL-based systems"
	@echo "  install-arch            	Install dependencies for Arch Linux"
	@echo "  linux                  	Install dependencies, build, and set up the project for Linux"
	@echo "  debug                   	Build and run the project in Debug mode"
	@echo "  release                 	Build and run the project in Release mode"
	@echo "  build-debug             	Build the project in Debug mode"
	@echo "  build-release           	Build the project in Release mode"
	@echo "  run-debug               	Run the Debug build"
	@echo "  run-release             	Run the Release build"
	@echo "  clean-debug             	Clean Debug build files"
	@echo "  clean-release           	Clean Release build files"
	@echo "  clean-debug-all         	Remove all Debug build files"
	@echo "  clean-release-all       	Remove all Release build files"
	@echo
	@echo "If no target is specified, the script will default to building the Debug version."
	@echo "You can also specify a target to run the corresponding command. For example:"
	@echo "  make help               	- Displays this help message."
	@echo "  make linux             	- Installs dependencies, builds, and sets up the project for Linux."
	@echo "  make debug              	- Builds the project in Debug mode and runs it."
	@echo "  make release            	- Builds the project in Release mode and runs it."
	@echo "  make clean-debug-all    	- Removes all Debug build files."
	@echo "  make clean-release-all  	- Removes all Release build files."

# Install for Linux
linux: install-dependencies build-linux install-desktop-file run-linux

install-dependencies:
	@echo "Detecting platform..."
	@sh ./${LINUX_INSTALL_FILE_PATH} install-dependencies

install-ubuntu:
	@echo "Installing dependencies for Ubuntu..."
	@sh ./${LINUX_INSTALL_FILE_PATH} install-ubuntu

install-fedora:
	@echo "Installing dependencies for Fedora..."
	@sh ./${LINUX_INSTALL_FILE_PATH} install-fedora
	
install-arch:
	@echo "Installing dependencies for Arch Linux..."
	@sh ./${LINUX_INSTALL_FILE_PATH} install-arch

build-linux:
	sudo cmake -S .. -B $(LINUX_BUILD_DIR) -G Ninja -DCMAKE_BUILD_TYPE=Release -DGLFW_BUILD_WAYLAND=OFF -DGLFW_BUILD_X11=ON
	sudo cmake --build $(LINUX_BUILD_DIR) -j8
	sudo ln -sf ${LINUX_BUILD_DIR}/${EXECUTABLE_PATH} /usr/local/bin/ferx

run-linux:
	ferx

install-desktop-file:
	sudo cmake --install ${LINUX_BUILD_DIR} --prefix /usr/
	
# Build project
debug: build-debug run-debug

release: build-release run-release

build-release:
	cmake -S .. -B ../$(RELEASE_BUILD_DIR) -G Ninja -DCMAKE_BUILD_TYPE=Release -DGLFW_BUILD_WAYLAND=OFF -DGLFW_BUILD_X11=ON
	cmake --build ../$(RELEASE_BUILD_DIR) -j8

build-debug:
	cmake -S .. -B ../$(DEBUG_BUILD_DIR) -G Ninja -DCMAKE_BUILD_TYPE=Debug -DGLFW_BUILD_WAYLAND=OFF -DGLFW_BUILD_X11=ON
	cmake --build ../$(DEBUG_BUILD_DIR) -j8

run-release:
	../$(RELEASE_BUILD_DIR)/${EXECUTABLE_PATH}

run-debug:
	../$(DEBUG_BUILD_DIR)/${EXECUTABLE_PATH}
	
clean-release:
	cmake --build ../$(RELEASE_BUILD_DIR) --target clean

clean-debug:
	cmake --build ../$(DEBUG_BUILD_DIR) --target clean

clean-release-all:
	$(RM) ../$(RELEASE_BUILD_DIR)

clean-debug-all:
	$(RM) ../$(DEBUG_BUILD_DIR)
