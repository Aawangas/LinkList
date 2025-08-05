#include<iostream>
#include<vector>
#include<queue>

// Definition for singly-linked list (compatible with LeetCode)
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Helper function to create list from array
ListNode* createList(std::vector<int>& nums) {
    if (nums.empty()) return nullptr;
    
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    
    for (int i = 1; i < nums.size(); i++) {
        current->next = new ListNode(nums[i]);
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

// LeetCode 2: Add Two Numbers
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* current = &dummy;
    int carry = 0;
    
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;
        
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        carry = sum / 10;
        current->next = new ListNode(sum % 10);
        current = current->next;
    }
    
    return dummy.next;
}

// LeetCode 23: Merge k Sorted Lists (using priority queue)
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    std::priority_queue<ListNode*, std::vector<ListNode*>, Compare> pq;
    
    // Add all non-null heads to priority queue
    for (ListNode* list : lists) {
        if (list != nullptr) {
            pq.push(list);
        }
    }
    
    ListNode dummy(0);
    ListNode* current = &dummy;
    
    while (!pq.empty()) {
        ListNode* node = pq.top();
        pq.pop();
        
        current->next = node;
        current = current->next;
        
        if (node->next != nullptr) {
            pq.push(node->next);
        }
    }
    
    return dummy.next;
}

// LeetCode 61: Rotate List
ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || head->next == nullptr || k == 0) {
        return head;
    }
    
    // Find length and make it circular
    ListNode* tail = head;
    int length = 1;
    while (tail->next != nullptr) {
        tail = tail->next;
        length++;
    }
    tail->next = head; // Make circular
    
    // Find new tail (length - k % length - 1 steps from head)
    k = k % length;
    int steps = length - k;
    ListNode* newTail = head;
    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }
    
    ListNode* newHead = newTail->next;
    newTail->next = nullptr; // Break the circle
    
    return newHead;
}

// LeetCode 143: Reorder List
void reorderList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    
    // Find middle
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse second half
    ListNode* second = slow->next;
    slow->next = nullptr;
    ListNode* prev = nullptr;
    
    while (second != nullptr) {
        ListNode* next = second->next;
        second->next = prev;
        prev = second;
        second = next;
    }
    
    // Merge two halves
    ListNode* first = head;
    second = prev;
    
    while (second != nullptr) {
        ListNode* firstNext = first->next;
        ListNode* secondNext = second->next;
        
        first->next = second;
        second->next = firstNext;
        
        first = firstNext;
        second = secondNext;
    }
}

// LeetCode 148: Sort List (Merge Sort)
ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* current = &dummy;
    
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val <= l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }
    
    current->next = (l1 != nullptr) ? l1 : l2;
    return dummy.next;
}

ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    // Find middle and split
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;
    
    while (fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    prev->next = nullptr; // Split the list
    
    // Recursively sort both halves
    ListNode* left = sortList(head);
    ListNode* right = sortList(slow);
    
    // Merge sorted halves
    return merge(left, right);
}

// LeetCode 25: Reverse Nodes in k-Group
ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr || k == 1) {
        return head;
    }
    
    // Check if we have k nodes
    ListNode* current = head;
    int count = 0;
    while (current != nullptr && count < k) {
        current = current->next;
        count++;
    }
    
    if (count == k) {
        // Reverse first k nodes
        current = reverseKGroup(current, k); // Recursively process rest
        
        // Reverse current k-group
        while (count > 0) {
            ListNode* next = head->next;
            head->next = current;
            current = head;
            head = next;
            count--;
        }
        head = current;
    }
    
    return head;
}

// Demonstration
int main() {
    std::cout << "=== More LeetCode Solutions Demo ===" << std::endl;
    
    // Test Add Two Numbers
    std::vector<int> num1 = {2, 4, 3}; // represents 342
    std::vector<int> num2 = {5, 6, 4}; // represents 465
    ListNode* l1 = createList(num1);
    ListNode* l2 = createList(num2);
    
    std::cout << "Add Two Numbers:" << std::endl;
    std::cout << "List 1: ";
    printList(l1);
    std::cout << "List 2: ";
    printList(l2);
    
    ListNode* sum = addTwoNumbers(l1, l2);
    std::cout << "Sum: ";
    printList(sum); // Should be 7 0 8 (represents 807)
    
    // Test Rotate List
    std::vector<int> nums = {1, 2, 3, 4, 5};
    ListNode* head = createList(nums);
    std::cout << "\nRotate List:" << std::endl;
    std::cout << "Original: ";
    printList(head);
    
    ListNode* rotated = rotateRight(head, 2);
    std::cout << "Rotated by 2: ";
    printList(rotated);
    
    // Test Sort List
    std::vector<int> unsorted = {4, 2, 1, 3};
    ListNode* unsortedList = createList(unsorted);
    std::cout << "\nSort List:" << std::endl;
    std::cout << "Unsorted: ";
    printList(unsortedList);
    
    ListNode* sorted = sortList(unsortedList);
    std::cout << "Sorted: ";
    printList(sorted);
    
    return 0;
}