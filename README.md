# Ferx

Ferx is a basic game engine written in c++

[![CMake on a single platform](https://github.com/coderloff/ferx/actions/workflows/cmake-single-platform.yml/badge.svg)](https://github.com/coderloff/ferx/actions/workflows/cmake-single-platform.yml)

## Build

To clone repo:
```bash
git clone https://github.com/coderloff/learnopengl
```

After clonning the repo, update the submodules:
```bash
git submodule update --init
```

That's it! You can build and run the project with `make` command

### Commands

Here is the list of each `make` command:

`make` - builds the project and runs it (default: debug)<br>
`make debug` - builds the project as debug<br>
`make release` - builds the project as release<br>
`make run` - runs the executable<br>
`make clean` - cleans the build target<br>
`make clean-all` - deletes build directory<br>

## Dependencies

Required dependencies: git cmake make ninja

## Libraries

* **GLFW**
* **GLAD**
* **GLM**
* **ImGUI*
