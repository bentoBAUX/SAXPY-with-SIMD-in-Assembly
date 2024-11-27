# Compiler flags
CFLAGS = -g -Wall -Wextra -std=c11 -O3
LDFLAGS = 

# Source and output directories
SRC_DIR = src
OUT_FILE = main

# Source files
SRC_FILES = $(SRC_DIR)/main.c $(SRC_DIR)/saxpy.S

.PHONY: all clean

# Default target
all: $(OUT_FILE)

# Build the executable
$(OUT_FILE): $(SRC_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(OUT_FILE) $(LDFLAGS)

# Clean up build files
clean:
	rm -f $(OUT_FILE)
