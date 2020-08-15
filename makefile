CC=g++
STD=c++11
CFLAGS=-Wall -Wextra -std=$(STD)

TARGET_NAME=./tp1
TMPOUT_NAME=tp1.out
BUILD_PATH=./build
SOURCE_PATH=./src
LIB_PATH=./include

SOURCE_EXT := cpp
SOURCES := $(shell find $(SOURCE_PATH) -path '*.$(SOURCE_EXT)')
OBJECTS := $(patsubst $(SOURCE_PATH)/%,$(BUILD_PATH)/%,$(SOURCES:.$(SOURCE_EXT)=.o))

all: $(TARGET_NAME)

$(BUILD_PATH)/%.o: $(SOURCE_PATH)/%.cpp $(LIB_PATH)/%.hpp
	mkdir -p $(BUILD_PATH)
	mkdir -p $(BUILD_PATH)/list
	$(CC) -c $(CFLAGS) -o $@ $<

$(TARGET_NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(BUILD_PATH)/$(TARGET_NAME) ./main.cpp $(OBJECTS)

clean:
	rm -rf $(BUILD_PATH)/*

run:
	$(BUILD_PATH)/$(TARGET_NAME)

mem:
	valgrind --leak-check=full --show-leak-kinds=all $(BUILD_PATH)/$(TARGET_NAME) < ./tests/sample.in > ./output/mem.log

test: $(TARGET_NAME)
	@bash run_tests.sh $(BUILD_PATH)/$(TARGET_NAME) $(TMPOUT_NAME)
