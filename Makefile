NAME=LowLevelGame

SRC_DIR = src
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
BUILD_DIR = build
# OUTPUT = $(NAME).o
OUTPUT = $(NAME)
CC = clang++
INCLUDE_PATH = -I/opt/homebrew/include -I/usr/local/include
LIBRARY_PATH = -L/opt/homebrew/lib -L/usr/local/lib
# -l flags for linker, -v for verbose, -Og for optimization, -Wall for warnings
CC_FLAGS = -v -g -Og -Wall -lSDL2 -lSDL2_image

all:
	$(CC) $(CC_FLAGS) $(INCLUDE_PATH) $(LIBRARY_PATH) $(SRC_FILES) -o $(BUILD_DIR)/$(OUTPUT)

clean:
	rm -rf $(BUILD_DIR)/*
	@echo "Cleaned build directory."

# Setup the project (for devs)
setup:
	mkdir build/

# TODO: Create script to generate app bundle for MacOS
generate_bundle:
	@echo "This has not been implemented yet :("
