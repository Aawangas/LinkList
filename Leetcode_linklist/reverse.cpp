#include<iostream>
#include<vector>

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Helper function to create a list from vector
ListNode* createList(std::vector<int>& values) {
    if (values.empty()) return nullptr;
    
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    
    for (int i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    
    return head;
}

// Helper function to print list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Original reverse function (iterative)
ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while(curr != nullptr){
        ListNode *next = curr ->next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
  return prev;
}

// Recursive version of reverse
ListNode* reverseListRecursive(ListNode* head) {
    // Base case
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    // Recursively reverse the rest of the list
    ListNode* newHead = reverseListRecursive(head->next);
    
    // Reverse the current connection
    head->next->next = head;
    head->next = nullptr;
    
    return newHead;
}

// Reverse between positions (LeetCode 92: Reverse Linked List II)
ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (head == nullptr || left == right) {
        return head;
    }
    
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    
    // Move prev to the node before left position
    for (int i = 1; i < left; i++) {
        prev = prev->next;
    }
    
    ListNode* current = prev->next;
    
    // Reverse the sublist from left to right
    for (int i = 0; i < right - left; i++) {
        ListNode* next = current->next;
        current->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }
    
    return dummy.next;
}

// Demo function
int main() {
    std::cout << "=== Linked List Reverse Demo ===" << std::endl;
    
    // Test basic reverse
    std::vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createList(values);
    
    std::cout << "Original list: ";
    printList(head);
    
    ListNode* reversed = reverseList(head);
    std::cout << "Reversed (iterative): ";
    printList(reversed);
    
    // Test recursive reverse
    std::vector<int> values2 = {1, 2, 3, 4, 5};
    ListNode* head2 = createList(values2);
    
    std::cout << "\nOriginal list: ";
    printList(head2);
    
    ListNode* reversedRecursive = reverseListRecursive(head2);
    std::cout << "Reversed (recursive): ";
    printList(reversedRecursive);
    
    // Test reverse between positions
    std::vector<int> values3 = {1, 2, 3, 4, 5};
    ListNode* head3 = createList(values3);
    
    std::cout << "\nOriginal list: ";
    printList(head3);
    
    ListNode* reversedBetween = reverseBetween(head3, 2, 4);
    std::cout << "Reversed between positions 2-4: ";
    printList(reversedBetween);
    
    // Test edge cases
    std::vector<int> singleValue = {42};
    ListNode* singleNode = createList(singleValue);
    
    std::cout << "\nSingle node: ";
    printList(singleNode);
    
    ListNode* reversedSingle = reverseList(singleNode);
    std::cout << "Reversed single node: ";
    printList(reversedSingle);
    
    // Test empty list
    ListNode* emptyList = reverseList(nullptr);
    std::cout << "\nReversed empty list: ";
    if (emptyList == nullptr) {
        std::cout << "nullptr (empty)" << std::endl;
    } else {
        printList(emptyList);
    }
    
    return 0;
}
