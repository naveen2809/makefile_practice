CC = gcc
CFLAGS = -c -Wall -I$(INC_DIR) -D DEBUG=$(DEBUG)
SRC_DIR = src
INC_DIR = inc
BUILD_DIR = build
LDFLAGS = -Wl,-Map=$(BUILD_DIR)/$(MAPFILE)

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))

DEBUG = 0

ifeq ($(DEBUG),1)
EXECUTABLE = mainDbg.elf
MAPFILE = mainDbg.map
CFLAGS += -g
else
EXECUTABLE = mainRel.elf
MAPFILE = mainRel.map
endif

all: dir $(BUILD_DIR)/$(EXECUTABLE)

dir:
	mkdir -p build

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

execute:
	./$(BUILD_DIR)/$(EXECUTABLE)

clean:
	rm -rf build

.PHONY: dir clean execute