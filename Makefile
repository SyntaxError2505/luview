TARGET := luview
CC := cc
CFLAGS := -std=c23 -Wall -Wextra
DEBUG ?= 1
SOURCE_DIR := ./src
SOURCE = $(shell find $(SOURCE_DIR) -type f -name "*.c")

ifeq ($(DEBUG), "1")
CFLAGS += -O0 -g
else
CFLAGS += -O2
endif

default: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) -o $(TARGET) $(CFLAGS) $(SOURCE)

clean:
	rm -f $(TARGET)

.PHONY: clean default
