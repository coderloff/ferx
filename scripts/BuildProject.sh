#!/bin/bash

BUILD_DIR="build"
EDITOR_DIR="editor"
NAME="ferx"

case $1 in
  release)
    cmake -S .. -B ../"$BUILD_DIR" -G Ninja -DCMAKE_BUILD_TYPE=Release
    cmake --build ../"$BUILD_DIR" -j8
    ;;
  debug)
    cmake -S .. -B ../"$BUILD_DIR" -G Ninja -DCMAKE_BUILD_TYPE=Debug
    cmake --build ../"$BUILD_DIR" -j8
    ;;
  run)
    cd "../$BUILD_DIR/$EDITOR_DIR" && ./"$NAME"
    ;;
  clean)
    cmake --build ../"$BUILD_DIR" --target clean
    ;;
  clean-all)
    rm -r ../"$BUILD_DIR"
    ;;
  all)
  	bash $0 enter_dir
    bash $0 debug
    bash $0 run
    ;;
  *)
    echo "Usage: $0 {release|debug|run|clean|clean-all|all}"
    exit 1
    ;;
esac
