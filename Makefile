# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -O2 -g

# Directories
LECTURE_DIR = From_lecture
LEETCODE_DIR = Leetcode_linklist

# Source files
LECTURE_SOURCES = $(wildcard $(LECTURE_DIR)/*.cpp)
LEETCODE_SOURCES = $(wildcard $(LEETCODE_DIR)/*.cpp)

# Executable names (remove .cpp extension and directory path)
LECTURE_EXECUTABLES = $(patsubst $(LECTURE_DIR)/%.cpp, %, $(LECTURE_SOURCES))
LEETCODE_EXECUTABLES = $(patsubst $(LEETCODE_DIR)/%.cpp, %, $(LEETCODE_SOURCES))

# All executables
ALL_EXECUTABLES = $(LECTURE_EXECUTABLES) $(LEETCODE_EXECUTABLES)

# Default target
.PHONY: all
all: $(ALL_EXECUTABLES)

# Build lecture programs
$(LECTURE_EXECUTABLES): %: $(LECTURE_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# Build leetcode programs  
$(LEETCODE_EXECUTABLES): %: $(LEETCODE_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# Individual targets for easy access
.PHONY: lecture leetcode

lecture: $(LECTURE_EXECUTABLES)
	@echo "Built all lecture programs: $(LECTURE_EXECUTABLES)"

leetcode: $(LEETCODE_EXECUTABLES)
	@echo "Built all leetcode programs: $(LEETCODE_EXECUTABLES)"

# Run targets
.PHONY: run-general run-advanced run-doubly run-memory run-intersection run-reverse run-more

run-general: general_operation
	@echo "=== Running General Operations ==="
	./general_operation

run-advanced: advanced_operations
	@echo "=== Running Advanced Operations ==="
	./advanced_operations

run-doubly: doubly_linked_list
	@echo "=== Running Doubly Linked List ==="
	./doubly_linked_list

run-memory: memory_management
	@echo "=== Running Memory Management ==="
	./memory_management

run-intersection: intersection
	@echo "=== Running Intersection (Note: requires ListNode definition) ==="
	@echo "This file contains functions only, no main function to run."

run-reverse: reverse
	@echo "=== Running Reverse (Note: requires ListNode definition) ==="
	@echo "This file contains functions only, no main function to run."

run-more: more_solutions
	@echo "=== Running More Solutions ==="
	./more_solutions

# Run all programs with main functions
.PHONY: run-all
run-all: run-general run-advanced run-doubly run-memory run-more
	@echo "=== All programs executed ==="

# Clean up executables
.PHONY: clean
clean:
	rm -f $(ALL_EXECUTABLES)
	@echo "Cleaned up all executables"

# Debug build
.PHONY: debug
debug: CXXFLAGS += -DDEBUG -g3 -O0
debug: $(ALL_EXECUTABLES)
	@echo "Built all programs in debug mode"

# Release build
.PHONY: release
release: CXXFLAGS += -DNDEBUG -O3
release: $(ALL_EXECUTABLES)
	@echo "Built all programs in release mode"

# Test build (compile only, don't link)
.PHONY: test-compile
test-compile:
	@echo "Testing compilation of all source files..."
	@for file in $(LECTURE_SOURCES) $(LEETCODE_SOURCES); do \
		echo "Compiling $$file..."; \
		$(CXX) $(CXXFLAGS) -c $$file -o /dev/null || exit 1; \
	done
	@echo "All files compiled successfully!"

# Help target
.PHONY: help
help:
	@echo "Available targets:"
	@echo "  all           - Build all programs"
	@echo "  lecture       - Build only lecture programs"
	@echo "  leetcode      - Build only leetcode programs"
	@echo "  run-general   - Run general operations demo"
	@echo "  run-advanced  - Run advanced operations demo"
	@echo "  run-doubly    - Run doubly linked list demo"
	@echo "  run-memory    - Run memory management demo"
	@echo "  run-more      - Run more leetcode solutions demo"
	@echo "  run-all       - Run all demos"
	@echo "  debug         - Build with debug flags"
	@echo "  release       - Build with release flags"
	@echo "  test-compile  - Test compilation without linking"
	@echo "  clean         - Remove all executables"
	@echo "  help          - Show this help message"
	@echo ""
	@echo "Individual programs:"
	@echo "  $(ALL_EXECUTABLES)"