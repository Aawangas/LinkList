# LinkList - Comprehensive C++ Linked List Implementation

This repository contains a comprehensive implementation of various linked list data structures and algorithms in C++. It serves as both a learning resource for understanding pointers and data structures, and a collection of practical implementations for common linked list problems.

## 🚀 Features

### Core Implementations
- **Singly Linked List** - Basic operations (insert, delete, search, print)
- **Doubly Linked List** - Bidirectional traversal with full CRUD operations
- **Advanced Operations** - Merge, cycle detection, palindrome checking, and more
- **Memory Management** - Safe implementations with proper destructors and smart pointers

### LeetCode Solutions
- **Intersection of Two Linked Lists** (LeetCode 160) - Two different approaches
- **Reverse Linked List** (LeetCode 206) - Iterative and recursive solutions
- **Add Two Numbers** (LeetCode 2) - Addition with carry handling
- **Merge k Sorted Lists** (LeetCode 23) - Priority queue approach
- **Rotate List** (LeetCode 61) - Circular rotation implementation
- **Sort List** (LeetCode 148) - Merge sort for linked lists
- **Reverse Nodes in k-Group** (LeetCode 25) - Advanced reversal patterns

## 📁 Project Structure

```
LinkList/
├── From_lecture/
│   ├── general_operation.cpp      # Basic linked list operations
│   ├── advanced_operations.cpp    # Advanced algorithms and operations
│   ├── doubly_linked_list.cpp     # Doubly linked list implementation
│   └── memory_management.cpp      # Memory-safe implementations
├── Leetcode_linklist/
│   ├── intersection.cpp           # Two approaches to find intersection
│   ├── reverse.cpp               # Multiple reverse algorithms
│   └── more_solutions.cpp        # Additional LeetCode problems
├── Makefile                      # Build automation
└── README.md                     # This documentation
```

## 🛠️ Building and Running

### Prerequisites
- C++ compiler with C++14 support (g++, clang++)
- Make utility (optional but recommended)

### Quick Start

```bash
# Build all programs
make all

# Build only lecture programs
make lecture

# Build only LeetCode solutions
make leetcode

# Run all demos
make run-all

# Run specific programs
make run-general      # Basic operations demo
make run-advanced     # Advanced algorithms demo
make run-doubly       # Doubly linked list demo
make run-memory       # Memory management demo
make run-more         # Additional LeetCode solutions
```

### Manual Compilation

```bash
# Compile individual files
g++ -std=c++14 -Wall -Wextra -O2 From_lecture/general_operation.cpp -o general_operation
g++ -std=c++14 -Wall -Wextra -O2 From_lecture/advanced_operations.cpp -o advanced_operations

# Run the programs
./general_operation
./advanced_operations
```

## 📚 Code Examples

### Basic Linked List Operations

```cpp
#include "From_lecture/general_operation.cpp"

int main() {
    int array[] = {1, 3, 5, 7, 9};
    int size = sizeof(array)/sizeof(array[0]);
    
    // Create linked list from array
    list_node *head = create_linklist(array, size);
    
    // Insert node at position 1
    list_node *insertion = initialize_node(2);
    insert_node(head, insertion, 1);
    
    // Print the list
    print_linklist(head);  // Output: 1 2 3 5 7 9
    
    return 0;
}
```

### Advanced Operations

```cpp
#include "From_lecture/advanced_operations.cpp"

int main() {
    // Create two sorted lists
    list_node* list1 = create_node(1);
    list1->next = create_node(3);
    list1->next->next = create_node(5);
    
    list_node* list2 = create_node(2);
    list2->next = create_node(4);
    list2->next->next = create_node(6);
    
    // Merge sorted lists
    list_node* merged = merge_sorted_lists(list1, list2);
    print_list(merged);  // Output: 1 2 3 4 5 6
    
    // Check for palindrome
    list_node* palindrome = create_node(1);
    palindrome->next = create_node(2);
    palindrome->next->next = create_node(1);
    
    bool isPalindrome = is_palindrome(palindrome);  // Returns true
    
    return 0;
}
```

### Memory-Safe Implementation

```cpp
#include "From_lecture/memory_management.cpp"

int main() {
    // Automatic memory management
    SafeLinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    
    // Use range-based for loop (C++11)
    for (int value : list) {
        std::cout << value << " ";
    }
    
    // Memory automatically freed when list goes out of scope
    return 0;
}
```

## 🎯 Algorithm Complexities

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Insert (beginning) | O(1) | O(1) |
| Insert (end) | O(n) | O(1) |
| Delete (beginning) | O(1) | O(1) |
| Delete (position) | O(n) | O(1) |
| Search | O(n) | O(1) |
| Reverse | O(n) | O(1) |
| Merge Sorted Lists | O(n + m) | O(1) |
| Cycle Detection | O(n) | O(1) |
| Palindrome Check | O(n) | O(n) |

## 🧪 Testing

The repository includes comprehensive test cases and demonstrations:

```bash
# Test compilation without linking
make test-compile

# Run specific test scenarios
make run-general    # Tests basic operations
make run-advanced   # Tests advanced algorithms
make run-memory     # Tests memory management
```

## 🎓 Learning Objectives

This codebase helps you understand:

1. **Pointer Manipulation** - Direct memory access and pointer arithmetic
2. **Dynamic Memory Allocation** - Using `new` and `delete` operators
3. **Data Structure Design** - Implementing abstract data types
4. **Algorithm Analysis** - Time and space complexity considerations
5. **Memory Management** - Preventing memory leaks and dangling pointers
6. **Modern C++ Features** - Smart pointers, RAII, move semantics

## 🔧 Advanced Features

### Smart Pointer Implementation
- Uses `std::unique_ptr` for automatic memory management
- Eliminates manual memory management concerns
- Provides exception safety

### Iterator Support
- Custom iterator implementation for range-based loops
- STL-compatible interface
- Forward iteration support

### Memory Leak Detection
- Built-in allocation tracking
- Automatic leak reporting
- Debug-friendly output

## 📖 LeetCode Problem Solutions

### Easy Problems
- **206. Reverse Linked List** - Both iterative and recursive solutions
- **160. Intersection of Two Linked Lists** - HashSet and two-pointer approaches

### Medium Problems
- **2. Add Two Numbers** - Handle carry propagation
- **61. Rotate List** - Circular list manipulation
- **143. Reorder List** - Complex pointer manipulation
- **148. Sort List** - Merge sort implementation

### Hard Problems
- **23. Merge k Sorted Lists** - Priority queue optimization
- **25. Reverse Nodes in k-Group** - Advanced reversal patterns

## 🚀 Performance Optimizations

- **Compiler Optimizations** - Uses `-O2` flag for release builds
- **Memory Efficiency** - Minimal memory overhead per node
- **Cache-Friendly** - Sequential memory access patterns where possible
- **Algorithm Selection** - Optimal algorithms for each operation

## 🤝 Contributing

Feel free to contribute by:
1. Adding new linked list algorithms
2. Implementing additional LeetCode solutions
3. Improving documentation
4. Adding test cases
5. Optimizing existing implementations

## 📝 Build Targets

| Target | Description |
|--------|-------------|
| `make all` | Build all programs |
| `make lecture` | Build lecture programs only |
| `make leetcode` | Build LeetCode solutions only |
| `make debug` | Build with debug symbols |
| `make release` | Build with optimizations |
| `make clean` | Remove all executables |
| `make help` | Show all available targets |

## 🏆 Key Achievements

- ✅ Complete singly linked list implementation
- ✅ Full-featured doubly linked list
- ✅ Advanced algorithms (merge, cycle detection, palindrome)
- ✅ Memory-safe implementations with RAII
- ✅ Comprehensive LeetCode solution collection
- ✅ Modern C++ features (smart pointers, iterators)
- ✅ Automated build system with Makefile
- ✅ Extensive documentation and examples

## 📚 References

- [LeetCode Linked List Problems](https://leetcode.com/tag/linked-list/)
- [C++ Reference Documentation](https://en.cppreference.com/)
- [Data Structures and Algorithms](https://www.geeksforgeeks.org/data-structures/)

---

**Note**: This codebase is designed for educational purposes and practical problem-solving. Each implementation includes detailed comments explaining the logic and approach used.
