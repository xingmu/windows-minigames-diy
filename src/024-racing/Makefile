# 024-racing Makefile
PROJECT = 024-racing
ZC = zc
SRC_DIR = src
SRC_FILES = $(SRC_DIR)/main_window.zc $(SRC_DIR)/platform_api.zc \
             $(SRC_DIR)/platform_api_windows.zc $(SRC_DIR)/game.zc
BUILD_DIR = build
TARGET = $(BUILD_DIR)/$(PROJECT).exe
ZC_FLAGS = -O2

all: build

build: $(TARGET)

$(TARGET): $(SRC_FILES)
	mkdir -p $(BUILD_DIR)
	$(ZC) $(ZC_FLAGS) -o $(TARGET) $(SRC_FILES)

run: $(TARGET)
	./$(TARGET)
