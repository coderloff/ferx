---
sidebar_position: 2
---

# Building Project

To clone repo:
```bash
git clone https://github.com/coderloff/ferx
```

After clonning the repo, update the submodules:
```bash
git submodule update --init
```

That's it! You can build and run the project by entering `scripts` directory and using `make` command or `BuildProject.sh` file.

## Commands

### Makefile
Here is the list of each `make` command:

- `make` - builds the project and runs it (default: debug)<br/>
- `make build-debug` - builds the project as debug<br/>
- `make build-release` - builds the project as release<br/>
- `make run-debug` - runs the executable of debug<br/>
- `make run-release` - runs the executable of release<br/>
- `make clean-debug` - cleans the build target of debug<br/>
- `make clean-release` - cleans the build target of release<br/>
- `make clean-debug-all` - deletes debug build directory<br/>
- `make clean-release-all` - deletes release build directory<br/>

### Shell file
Here is the list of each `BuildProject.sh` command:

- `./BuildProject.sh all` - builds the project and runs it (default: debug)<br/>
- `./BuildProject.sh build-debug` - builds the project as debug<br/>
- `./BuildProject.sh build-release` - builds the project as release<br/>
- `./BuildProject.sh run-debug` - runs the executable of debug<br/>
- `./BuildProject.sh run-release` - runs the executable of release<br/>
- `./BuildProject.sh clean-debug` - cleans the build target of debug<br/>
- `./BuildProject.sh clean-release` - cleans the build target of release<br/>
- `./BuildProject.sh clean-debug-all` - deletes debug build directory<br/>
- `./BuildProject.sh clean-release-all` - deletes release build directory<br/>


## Dependencies

Required dependencies: `git`, `cmake`, `make`, `ninja`