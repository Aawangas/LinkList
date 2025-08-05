#include<iostream>
#include<stack>

struct list_node
{
    int value;
    list_node * next;
    
    list_node() : value(0), next(nullptr) {}
    list_node(int val) : value(val), next(nullptr) {}
};

// Helper function to create a new node
list_node* create_node(int value) {
    list_node* node = new list_node;
    node->value = value;
    node->next = nullptr;
    return node;
}

// Helper function to print linked list
void print_list(list_node* head) {
    while (head != nullptr) {
        std::cout << head->value << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Merge two sorted linked lists
list_node* merge_sorted_lists(list_node* list1, list_node* list2) {
    list_node dummy(0);
    list_node* current = &dummy;
    
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->value <= list2->value) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    
    // Attach remaining nodes
    current->next = (list1 != nullptr) ? list1 : list2;
    
    return dummy.next;
}

// Detect cycle in linked list using Floyd's algorithm
bool has_cycle(list_node* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    
    list_node* slow = head;
    list_node* fast = head;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            return true;
        }
    }
    
    return false;
}

// Find the starting point of cycle in linked list
list_node* find_cycle_start(list_node* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    
    list_node* slow = head;
    list_node* fast = head;
    
    // Find if cycle exists
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            break;
        }
    }
    
    // No cycle found
    if (fast == nullptr || fast->next == nullptr) {
        return nullptr;
    }
    
    // Find the start of cycle
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;
}

// Check if linked list is palindrome
bool is_palindrome(list_node* head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }
    
    std::stack<int> values;
    list_node* current = head;
    
    // Push all values to stack
    while (current != nullptr) {
        values.push(current->value);
        current = current->next;
    }
    
    // Compare with original list
    current = head;
    while (current != nullptr) {
        if (current->value != values.top()) {
            return false;
        }
        values.pop();
        current = current->next;
    }
    
    return true;
}

// Remove nth node from end
list_node* remove_nth_from_end(list_node* head, int n) {
    list_node dummy(0);
    dummy.next = head;
    
    list_node* first = &dummy;
    list_node* second = &dummy;
    
    // Move first pointer n+1 steps ahead
    for (int i = 0; i <= n; i++) {
        first = first->next;
    }
    
    // Move both pointers until first reaches end
    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }
    
    // Remove the nth node from end
    list_node* to_delete = second->next;
    second->next = second->next->next;
    delete to_delete;
    
    return dummy.next;
}

// Find middle of linked list
list_node* find_middle(list_node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    
    list_node* slow = head;
    list_node* fast = head;
    
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

// Demonstration function
int main() {
    std::cout << "=== Advanced Linked List Operations Demo ===" << std::endl;
    
    // Create two sorted lists for merging
    list_node* list1 = create_node(1);
    list1->next = create_node(3);
    list1->next->next = create_node(5);
    
    list_node* list2 = create_node(2);
    list2->next = create_node(4);
    list2->next->next = create_node(6);
    
    std::cout << "List 1: ";
    print_list(list1);
    std::cout << "List 2: ";
    print_list(list2);
    
    list_node* merged = merge_sorted_lists(list1, list2);
    std::cout << "Merged: ";
    print_list(merged);
    
    // Test palindrome
    list_node* palindrome_list = create_node(1);
    palindrome_list->next = create_node(2);
    palindrome_list->next->next = create_node(1);
    
    std::cout << "Palindrome test (1->2->1): " << (is_palindrome(palindrome_list) ? "Yes" : "No") << std::endl;
    
    // Test middle finding
    list_node* middle = find_middle(merged);
    if (middle != nullptr) {
        std::cout << "Middle element: " << middle->value << std::endl;
    }
    
    return 0;
}