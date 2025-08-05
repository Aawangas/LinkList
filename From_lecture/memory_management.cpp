#include<iostream>
#include<memory>

struct list_node {
    int value;
    list_node* next;
    
    list_node(int val) : value(val), next(nullptr) {}
};

// Memory-safe linked list class
class SafeLinkedList {
private:
    list_node* head;
    int size;

public:
    SafeLinkedList() : head(nullptr), size(0) {}
    
    // Destructor - automatically cleans up memory
    ~SafeLinkedList() {
        clear();
    }
    
    // Copy constructor
    SafeLinkedList(const SafeLinkedList& other) : head(nullptr), size(0) {
        list_node* current = other.head;
        while (current != nullptr) {
            push_back(current->value);
            current = current->next;
        }
    }
    
    // Assignment operator
    SafeLinkedList& operator=(const SafeLinkedList& other) {
        if (this != &other) {
            clear();
            list_node* current = other.head;
            while (current != nullptr) {
                push_back(current->value);
                current = current->next;
            }
        }
        return *this;
    }
    
    // Move constructor
    SafeLinkedList(SafeLinkedList&& other) noexcept : head(other.head), size(other.size) {
        other.head = nullptr;
        other.size = 0;
    }
    
    // Move assignment operator
    SafeLinkedList& operator=(SafeLinkedList&& other) noexcept {
        if (this != &other) {
            clear();
            head = other.head;
            size = other.size;
            other.head = nullptr;
            other.size = 0;
        }
        return *this;
    }
    
    void push_front(int value) {
        list_node* new_node = new list_node(value);
        new_node->next = head;
        head = new_node;
        size++;
    }
    
    void push_back(int value) {
        list_node* new_node = new list_node(value);
        
        if (head == nullptr) {
            head = new_node;
        } else {
            list_node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_node;
        }
        size++;
    }
    
    bool pop_front() {
        if (head == nullptr) {
            return false;
        }
        
        list_node* to_delete = head;
        head = head->next;
        delete to_delete;
        size--;
        return true;
    }
    
    bool pop_back() {
        if (head == nullptr) {
            return false;
        }
        
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            size--;
            return true;
        }
        
        list_node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        
        delete current->next;
        current->next = nullptr;
        size--;
        return true;
    }
    
    void clear() {
        while (head != nullptr) {
            list_node* to_delete = head;
            head = head->next;
            delete to_delete;
        }
        size = 0;
    }
    
    void print() const {
        list_node* current = head;
        std::cout << "[";
        while (current != nullptr) {
            std::cout << current->value;
            if (current->next != nullptr) {
                std::cout << ", ";
            }
            current = current->next;
        }
        std::cout << "]" << std::endl;
    }
    
    int get_size() const {
        return size;
    }
    
    bool empty() const {
        return head == nullptr;
    }
    
    // Iterator-like access
    class iterator {
    private:
        list_node* current;
        
    public:
        iterator(list_node* node) : current(node) {}
        
        int& operator*() {
            return current->value;
        }
        
        iterator& operator++() {
            if (current != nullptr) {
                current = current->next;
            }
            return *this;
        }
        
        bool operator!=(const iterator& other) const {
            return current != other.current;
        }
        
        bool operator==(const iterator& other) const {
            return current == other.current;
        }
    };
    
    iterator begin() {
        return iterator(head);
    }
    
    iterator end() {
        return iterator(nullptr);
    }
};

// Smart pointer version using unique_ptr
struct smart_node {
    int value;
    std::unique_ptr<smart_node> next;
    
    smart_node(int val) : value(val), next(nullptr) {}
};

class SmartLinkedList {
private:
    std::unique_ptr<smart_node> head;
    int size;

public:
    SmartLinkedList() : head(nullptr), size(0) {}
    
    // No need for explicit destructor - unique_ptr handles cleanup automatically
    
    void push_front(int value) {
        auto new_node = std::make_unique<smart_node>(value);
        new_node->next = std::move(head);
        head = std::move(new_node);
        size++;
    }
    
    void push_back(int value) {
        auto new_node = std::make_unique<smart_node>(value);
        
        if (!head) {
            head = std::move(new_node);
        } else {
            smart_node* current = head.get();
            while (current->next) {
                current = current->next.get();
            }
            current->next = std::move(new_node);
        }
        size++;
    }
    
    bool pop_front() {
        if (!head) {
            return false;
        }
        
        head = std::move(head->next);
        size--;
        return true;
    }
    
    void print() const {
        smart_node* current = head.get();
        std::cout << "[";
        while (current) {
            std::cout << current->value;
            if (current->next) {
                std::cout << ", ";
            }
            current = current->next.get();
        }
        std::cout << "]" << std::endl;
    }
    
    int get_size() const {
        return size;
    }
    
    bool empty() const {
        return !head;
    }
};

// Memory leak detection helper
class MemoryTracker {
private:
    static int allocations;
    static int deallocations;

public:
    static void* operator new(size_t size) {
        allocations++;
        std::cout << "Allocating " << size << " bytes (total allocations: " << allocations << ")" << std::endl;
        return malloc(size);
    }
    
    static void operator delete(void* ptr) {
        deallocations++;
        std::cout << "Deallocating memory (total deallocations: " << deallocations << ")" << std::endl;
        free(ptr);
    }
    
    static void report() {
        std::cout << "=== Memory Report ===" << std::endl;
        std::cout << "Total allocations: " << allocations << std::endl;
        std::cout << "Total deallocations: " << deallocations << std::endl;
        std::cout << "Memory leaks: " << (allocations - deallocations) << std::endl;
    }
};

int MemoryTracker::allocations = 0;
int MemoryTracker::deallocations = 0;

// Demonstration
int main() {
    std::cout << "=== Memory Management Demo ===" << std::endl;
    
    // Test safe linked list
    {
        std::cout << "\n--- Safe Linked List ---" << std::endl;
        SafeLinkedList list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        list.push_front(0);
        
        std::cout << "List contents: ";
        list.print();
        std::cout << "Size: " << list.get_size() << std::endl;
        
        // Test copy constructor
        SafeLinkedList copy_list = list;
        std::cout << "Copied list: ";
        copy_list.print();
        
        // Test iterator
        std::cout << "Using iterator: ";
        for (auto it = list.begin(); it != list.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
        // Test range-based for loop (C++11)
        std::cout << "Range-based loop: ";
        for (int value : list) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
        
    } // list destructor called here automatically
    
    // Test smart pointer version
    {
        std::cout << "\n--- Smart Pointer Linked List ---" << std::endl;
        SmartLinkedList smart_list;
        smart_list.push_back(10);
        smart_list.push_back(20);
        smart_list.push_back(30);
        
        std::cout << "Smart list contents: ";
        smart_list.print();
        std::cout << "Size: " << smart_list.get_size() << std::endl;
        
        smart_list.pop_front();
        std::cout << "After pop_front: ";
        smart_list.print();
        
    } // smart_list destructor called here automatically
    
    std::cout << "\nAll memory should be automatically cleaned up!" << std::endl;
    
    return 0;
}