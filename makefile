CC=g++
STD=c++11
CFLAGS=-Wall -Wextra -std=$(STD)

TARGET_NAME=./tp1
TMPOUT_NAME=tp1.out
BUILD_PATH=./build
SOURCE_PATH=./src
LIB_PATH=./include
INPUT_PATH=./input
OUTPUT_PATH=./output
RUN_TEST=08

SOURCE_EXT := cpp
SOURCES := $(shell find $(SOURCE_PATH) -path '*.$(SOURCE_EXT)')
OBJECTS := $(patsubst $(SOURCE_PATH)/%,$(BUILD_PATH)/%,$(SOURCES:.$(SOURCE_EXT)=.o))

all: $(TARGET_NAME)

$(BUILD_PATH)/%.o: $(SOURCE_PATH)/%.cpp $(LIB_PATH)/%.hpp
	mkdir -p $(BUILD_PATH)
	mkdir -p $(BUILD_PATH)/list
	$(CC) -c $(CFLAGS) -o $@ $<

$(TARGET_NAME): $(OBJECTS) ./main.cpp
	$(CC) $(CFLAGS) -o $(TARGET_NAME) ./main.cpp $(OBJECTS)

clean:
	rm -rf $(BUILD_PATH)/*
	rm $(TARGET_NAME)

run:
	$(TARGET_NAME) $(INPUT_PATH)/$(RUN_TEST).in > $(OUTPUT_PATH)/$(RUN_TEST).out

mem:
	valgrind --leak-check=full --show-leak-kinds=all $(TARGET_NAME) $(INPUT_PATH)/$(RUN_TEST).in > ./output/mem.log

time:
	@bash time.sh $(TARGET_NAME) $(TMPOUT_NAME)

tests:
	@bash run_tests.sh $(TARGET_NAME) $(TMPOUT_NAME)
