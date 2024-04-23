BUILD_DIR = build

RM += -r

all: debug

release:
	cmake -S . -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=Release
	cmake --build $(BUILD_DIR) -j8

debug:
	cmake -S . -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=Debug
	cmake --build $(BUILD_DIR) -j8

clean:
	cmake --build $(BUILD_DIR) --target clean

clean-all:
	$(RM) $(BUILD_DIR)
