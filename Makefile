SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Files
SRC_FILES = $(shell find $(SRC_DIR) -name "*.cpp")
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Targets
EXECUTABLE = gomoku

# Flags
CXXFLAGS = -Wall -Wextra
DEBUGFLAGS = -g

# Rules
all: $(BUILD_DIR) $(EXECUTABLE)

debug: CXXFLAGS += $(DEBUGFLAGS)
debug: clean all

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

clean:
	find $(BUILD_DIR) -name "*.o" -type f -delete

fclean: clean
	rm -f $(EXECUTABLE)

re: fclean all