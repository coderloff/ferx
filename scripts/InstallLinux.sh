#!/bin/bash

# Set variables
LINUX_BUILD_DIR="/usr/local/lib/ferx"
EXECUTABLE_PATH="$LINUX_BUILD_DIR/editor/ferx"

# Detect the Linux distribution
detect_distro() {
    if [ -f /etc/os-release ]; then
        . /etc/os-release

        if [[ "$ID_LIKE" == *"ubuntu"* ]] || [[ "$ID_LIKE" == *"debian"* ]]; then
            echo "ubuntu"
        
        elif [[ "$ID_LIKE" == *"rhel"* ]] || [[ "$ID_LIKE" == *"centos"* ]] || [[ "$ID_LIKE" == *"fedora"* ]]; then
            echo "fedora"
        
        elif [[ "$ID_LIKE" == *"arch"* ]]; then
            echo "arch"
        
        else
            echo "$ID"
        fi
    else
        echo "unknown"
    fi
}

install_ubuntu() {
    echo "Installing dependencies for Ubuntu/Debian..."
    sudo apt update && sudo apt install -y libxkbcommon-dev libxinerama-dev libwayland-dev libxrandr-dev libxcursor-dev libxi-dev mesa-common-dev
}

install_fedora() {
    echo "Installing dependencies for Fedora/RHEL/CentOS..."
    sudo dnf install -y libxkbcommon-devel libXinerama-devel wayland-devel libXrandr-devel libXcursor-devel libXi-devel mesa-libGL-devel
}

install_arch() {
    echo "Installing dependencies for Arch Linux..."
    sudo pacman -Syu libxkbcommon libxinerama wayland libxrandr libxcursor libxi mesa
}

# Install Linux Dependencies
install_dependencies() {
	distro=$(detect_distro)

	case "$distro" in
		ubuntu)
			install_ubuntu
		;;
		fedora)
			install_fedora
		;;
		arch)
			install_arch
		;;
		*)
			echo "Unsupported distribution: $distro"
			exit 1
		;;
	esac
}

# Build project in global directory
build(){
    echo "Building project..."
	sudo cmake -S .. -B "$LINUX_BUILD_DIR" -G Ninja -DCMAKE_BUILD_TYPE=Release -DGLFW_BUILD_WAYLAND=OFF -DGLFW_BUILD_X11=ON
	sudo cmake --build "$LINUX_BUILD_DIR" -j8

    echo "Creating symbolic link for executable..."
	sudo ln -sf "$EXECUTABLE_PATH" /usr/local/bin/ferx
}

# Install .desktop file
install_desktop_file() {
    if [ ! -d "$LINUX_BUILD_DIR" ]; then
        echo "Build directory not found! Please build the project first."
        exit 1
    fi

    echo "Installing configurations..."
    sudo cmake --install "$LINUX_BUILD_DIR" --prefix /usr/
}

case $1 in
	install-dependencies)
		install_dependencies
	;;
	install-ubuntu)
		install_ubuntu
	;;
	install-fedora)
		install_fedora
	;;
	install-arch)
		install_arch
	;;
	--help)
	    echo "Usage: $0 <command>"
	    echo
	    echo "This script helps with the installation and setup of the Ferx project."
	    echo "It supports installing dependencies, building the project, and creating symlinks for easy access."
	    echo
	    echo "Commands:"
	    echo "  install-dependencies    	- Automatically installs dependencies based on the detected Linux distribution"
	    echo "  install-ubuntu          	- Installs dependencies using apt for Ubuntu/Debian"
	    echo "  install-fedora          	- Installs dependencies using dnf for Fedora/RHEL"
	    echo "  install-arch            	- Installs dependencies using pacman for Arch Linux"
	    echo "  build                   	- Builds the project and installs it into /usr/local/lib/ferx"
	    echo "  install-desktop-file    	- Installs the .desktop file and creates a symbolic link to the executable"
	    echo
	    echo "If no command is specified, the script will automatically follow all steps:"
	    echo "  1. Install dependencies based on your Linux distribution"
	    echo "  2. Build the project and install it into /usr/local/lib/ferx"
	    echo "  3. Install the .desktop file and create a symbolic link for easy access"
	    echo
	    echo "Examples:"
	    echo "  $0 install-dependencies 	- Automatically installs dependencies based on your distribution."
	    echo "  $0 build                	- Builds the project in /usr/local/lib/ferx."
	    echo "  $0 install-desktop-file 	- Installs the .desktop file and creates a symlink."
	    echo "  $0                      	- Executes all steps: installs dependencies, builds the project, and installs the desktop file."
	    echo
	    echo "To run the full process without specifying a command, just run the script without arguments."
	    echo "It will automatically handle installing dependencies, building the project, and installing the desktop file."
	    echo
	;;
	*)
		install_dependencies
		build
		install_desktop_file

		echo "Installation complete!"
	;;
esac
