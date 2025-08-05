#include<iostream>

struct doubly_node {
    int value;
    doubly_node* next;
    doubly_node* prev;
    
    doubly_node(int val) : value(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    doubly_node* head;
    doubly_node* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    
    // Destructor to free memory
    ~DoublyLinkedList() {
        clear();
    }
    
    // Insert at the beginning
    void insert_front(int value) {
        doubly_node* new_node = new doubly_node(value);
        
        if (head == nullptr) {
            head = tail = new_node;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        size++;
    }
    
    // Insert at the end
    void insert_back(int value) {
        doubly_node* new_node = new doubly_node(value);
        
        if (tail == nullptr) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        size++;
    }
    
    // Insert at specific position
    void insert_at(int position, int value) {
        if (position < 0 || position > size) {
            std::cout << "Invalid position!" << std::endl;
            return;
        }
        
        if (position == 0) {
            insert_front(value);
            return;
        }
        
        if (position == size) {
            insert_back(value);
            return;
        }
        
        doubly_node* new_node = new doubly_node(value);
        doubly_node* current = head;
        
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
        
        new_node->next = current;
        new_node->prev = current->prev;
        current->prev->next = new_node;
        current->prev = new_node;
        size++;
    }
    
    // Delete from front
    void delete_front() {
        if (head == nullptr) {
            std::cout << "List is empty!" << std::endl;
            return;
        }
        
        doubly_node* to_delete = head;
        
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        
        delete to_delete;
        size--;
    }
    
    // Delete from back
    void delete_back() {
        if (tail == nullptr) {
            std::cout << "List is empty!" << std::endl;
            return;
        }
        
        doubly_node* to_delete = tail;
        
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        
        delete to_delete;
        size--;
    }
    
    // Delete at specific position
    void delete_at(int position) {
        if (position < 0 || position >= size) {
            std::cout << "Invalid position!" << std::endl;
            return;
        }
        
        if (position == 0) {
            delete_front();
            return;
        }
        
        if (position == size - 1) {
            delete_back();
            return;
        }
        
        doubly_node* current = head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
        
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size--;
    }
    
    // Search for a value
    int find(int value) {
        doubly_node* current = head;
        int position = 0;
        
        while (current != nullptr) {
            if (current->value == value) {
                return position;
            }
            current = current->next;
            position++;
        }
        
        return -1; // Not found
    }
    
    // Print forward
    void print_forward() {
        std::cout << "Forward: ";
        doubly_node* current = head;
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    
    // Print backward
    void print_backward() {
        std::cout << "Backward: ";
        doubly_node* current = tail;
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }
    
    // Get size
    int get_size() const {
        return size;
    }
    
    // Check if empty
    bool is_empty() const {
        return size == 0;
    }
    
    // Clear all nodes
    void clear() {
        while (head != nullptr) {
            doubly_node* to_delete = head;
            head = head->next;
            delete to_delete;
        }
        tail = nullptr;
        size = 0;
    }
    
    // Reverse the list
    void reverse() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        
        doubly_node* current = head;
        doubly_node* temp = nullptr;
        
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        
        if (temp != nullptr) {
            head = temp->prev;
        }
        
        // Swap head and tail
        temp = head;
        head = tail;
        tail = temp;
    }
};

// Demonstration
int main() {
    std::cout << "=== Doubly Linked List Demo ===" << std::endl;
    
    DoublyLinkedList dll;
    
    // Insert elements
    dll.insert_back(1);
    dll.insert_back(2);
    dll.insert_back(3);
    dll.insert_front(0);
    dll.insert_at(2, 10);
    
    std::cout << "After insertions:" << std::endl;
    dll.print_forward();
    dll.print_backward();
    std::cout << "Size: " << dll.get_size() << std::endl;
    
    // Search
    int pos = dll.find(10);
    std::cout << "Position of 10: " << pos << std::endl;
    
    // Delete operations
    dll.delete_front();
    dll.delete_back();
    dll.delete_at(1);
    
    std::cout << "\nAfter deletions:" << std::endl;
    dll.print_forward();
    dll.print_backward();
    
    // Reverse
    dll.reverse();
    std::cout << "\nAfter reverse:" << std::endl;
    dll.print_forward();
    dll.print_backward();
    
    return 0;
}