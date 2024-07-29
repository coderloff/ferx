BUILD_DIR = build
EDITOR_DIR = editor
NAME = ferx

RM += -r

all: debug run

release:
	cmake -S . -B $(BUILD_DIR) -G Ninja -DCMAKE_BUILD_TYPE=Release
	cmake --build $(BUILD_DIR) -j8

debug:
	cmake -S . -B $(BUILD_DIR) -G Ninja -DCMAKE_BUILD_TYPE=Debug
	cmake --build $(BUILD_DIR) -j8

run:
	cd $(BUILD_DIR)/${EDITOR_DIR} && ./${NAME}

clean:
	cmake --build $(BUILD_DIR) --target clean

clean-all:
	$(RM) $(BUILD_DIR)
