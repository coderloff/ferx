BUILD_DIR = build

all: build

build:
	cmake -S ./ -B $(BUILD_DIR)
	cd $(BUILD_DIR) && make
	
clean:
	rm -rf $(BUILD_DIR)
