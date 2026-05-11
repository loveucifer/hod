CC      = gcc
CFLAGS  = -Wall -Wextra -std=c99 -O2 -I$(SRC_DIR)
LDFLAGS = -lm

SRC_DIR   = src
BUILD_DIR = build

TARGET = $(BUILD_DIR)/hod

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

.PHONY: all build run clean

all: build

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)/hod.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

build: $(TARGET)

run: build
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)
