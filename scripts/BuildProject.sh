#!/bin/bash

RELEASE_BUILD_DIR="build-release"
DEBUG_BUILD_DIR="build-debug"
EDITOR_DIR="editor"
NAME="ferx"

case $1 in
  build-release)
    cmake -S .. -B ../"$RELEASE_BUILD_DIR" -G Ninja -DCMAKE_BUILD_TYPE=Release
    cmake --build ../"$RELEASE_BUILD_DIR" -j8
    ;;
  build-debug)
    cmake -S .. -B ../"$DEBUG_BUILD_DIR" -G Ninja -DCMAKE_BUILD_TYPE=Debug
    cmake --build ../"$DEBUG_BUILD_DIR" -j8
    ;;
  run-release)
    cd "../$RELEASE_BUILD_DIR/$EDITOR_DIR" && ./"$NAME"
    ;;
  run-debug)
    cd "../$DEBUG_BUILD_DIR/$EDITOR_DIR" && ./"$NAME"
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
  *)
    echo "Usage: $0 {all|build-release|build-debug|run-release|run-debug|clean-release|clean-debug|clean-release-all|clean-debug-all}"
    exit 1
    ;;
esac
