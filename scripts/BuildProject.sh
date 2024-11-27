#!/bin/bash

# Set variables
RELEASE_BUILD_DIR="build-release"
DEBUG_BUILD_DIR="build-debug"
EXECUTABLE_PATH="editor/ferx"

# Run commands
case $1 in
  build-release)
    cmake -S .. -B ../"$RELEASE_BUILD_DIR" -G Ninja -DCMAKE_BUILD_TYPE=Release -DGLFW_BUILD_WAYLAND=OFF -DGLFW_BUILD_X11=ON
    cmake --build ../"$RELEASE_BUILD_DIR" -j8
    ;;
  build-debug)
    cmake -S .. -B ../"$DEBUG_BUILD_DIR" -G Ninja -DCMAKE_BUILD_TYPE=Debug -DGLFW_BUILD_WAYLAND=OFF -DGLFW_BUILD_X11=ON
    cmake --build ../"$DEBUG_BUILD_DIR" -j8
    ;;
  run-release)
    "../$RELEASE_BUILD_DIR/$EXECUTABLE_PATH"
    ;;
  run-debug)
    "../$DEBUG_BUILD_DIR/$EXECUTABLE_PATH"
    ;;
  clean-release)
    cmake --build ../"$RELEASE_BUILD_DIR" --target clean
    ;;
  clean-debug)
    cmake --build ../"$DEBUG_BUILD_DIR" --target clean
    ;;
  clean-release-all)
    rm -r ../"$RELEASE_BUILD_DIR"
    ;;
  clean-debug-all)
    rm -r ../"$DEBUG_BUILD_DIR"
    ;;
  all)
    bash $0 build-debug
    bash $0 run-debug
    ;;
  --help)
    echo "Usage: $0 <command>"
    echo
    echo "Commands:"
    echo "  all                Build and run the project in Debug mode"
    echo "  build-release      Build the project in Release mode"
    echo "  build-debug        Build the project in Debug mode"
    echo "  run-release        Run the Release build"
    echo "  run-debug          Run the Debug build"
    echo "  clean-release      Clean Release build files"
    echo "  clean-debug        Clean Debug build files"
    echo "  clean-release-all  Remove all Release build files"
    echo "  clean-debug-all    Remove all Debug build files"
    ;;
  *)
    echo "Unknown command: $1"
    echo "Use --help for a list of available commands"
    exit 1
    ;;
esac
