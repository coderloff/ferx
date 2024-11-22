DEBUG_BUILD_DIR = build-debug
RELEASE_BUILD_DIR = build-release
EDITOR_DIR = editor
NAME = ferx

RM += -r

all: build-debug run-debug

build-release:
	cmake -S .. -B ../$(RELEASE_BUILD_DIR) -G Ninja -DCMAKE_BUILD_TYPE=Release
	cmake --build ../$(RELEASE_BUILD_DIR) -j8

build-debug:
	cmake -S .. -B ../$(DEBUG_BUILD_DIR) -G Ninja -DCMAKE_BUILD_TYPE=Debug
	cmake --build ../$(DEBUG_BUILD_DIR) -j8

run-release:
	cd ../$(RELEASE_BUILD_DIR)/${EDITOR_DIR} && ./${NAME}

run-debug:
	cd ../$(DEBUG_BUILD_DIR)/${EDITOR_DIR} && ./${NAME}
	
clean-release:
	cmake --build ../$(RELEASE_BUILD_DIR) --target clean

clean-debug:
	cmake --build ../$(DEBUG_BUILD_DIR) --target clean

clean-release-all:
	$(RM) ../$(RELEASE_BUILD_DIR)

clean-debug-all:
	$(RM) ../$(DEBUG_BUILD_DIR)
