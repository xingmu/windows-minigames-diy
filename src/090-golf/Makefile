# Makefile for Zen-C Golf Game

ZC = zc
TARGET = golf.exe
SRCDIR = src
BUILD_DIR = build

SOURCES = $(wildcard $(SRCDIR)/*.zc)

ZCFLAGS = -O2 -Wall

all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(SOURCES)
	@mkdir -p $(BUILD_DIR)
	$(ZC) $(ZCFLAGS) -o $@ $(SOURCES)

clean:
	rm -f $(BUILD_DIR)/*

run: $(BUILD_DIR)/$(TARGET)
	./$(BUILD_DIR)/$(TARGET)
