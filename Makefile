# Makefile for 020-SuperMario

PROJECT = 020-supermario
SRC_DIR = src
BUILD_DIR = build
ZCC = zc

SOURCES = $(SRC_DIR)/main_window.zc
TARGET = $(BUILD_DIR)/$(PROJECT).exe

CFLAGS = -O2

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SOURCES)
	mkdir -p $(BUILD_DIR)
	$(ZCC) $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
	cd $(BUILD_DIR) && del /Q *.exe 2>nul || true

run: $(TARGET)
	$(TARGET)
