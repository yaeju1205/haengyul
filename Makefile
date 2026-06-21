CC := gcc

SRC_DIR := src
BUILD_DIR := target
TARGET := target/haengyul

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) -c $< -o $@

dev: $(TARGET)
	./$(TARGET)
	$(MAKE) clean

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean
