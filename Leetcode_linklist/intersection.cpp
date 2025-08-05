#include<iostream>
#include<unordered_set>
#include<vector>

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Helper function to create a list
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

ListNode *getIntersectionNode_1(ListNode *headA, ListNode *headB) {
    /*That method uses hashtable to check if something in B occured in A*/
    std::unordered_set<ListNode*> visited;
    ListNode *current = headA;
    for (;current != nullptr; current = current -> next){
        visited.insert(current);
    }
    current = headB;
    for(;current!=nullptr;current = current -> next){
       if(visited.count(current)){
           return current;
        }
    }
    return nullptr;
}

ListNode *getIntersectionNode_2(ListNode *headA, ListNode *headB) {
    //A = a+m, B = b+m, A+b = a+B, they will reach the same point at the same time.
    if (headA == nullptr || headB == nullptr) {
        return nullptr;
    }
    ListNode *pA = headA, *pB = headB;
    while (pA != pB) {
        pA = pA == nullptr ? headB : pA->next;
        pB = pB == nullptr ? headA : pB->next;
    }
    return pA;
}

// Demo function
int main() {
    std::cout << "=== Linked List Intersection Demo ===" << std::endl;
    
    // Create two lists that intersect
    // List A: 4 -> 1 -> 8 -> 4 -> 5
    // List B: 5 -> 6 -> 1 -> 8 -> 4 -> 5
    // They intersect at node with value 8
    
    ListNode* intersectionNode = new ListNode(8);
    intersectionNode->next = new ListNode(4);
    intersectionNode->next->next = new ListNode(5);
    
    // Create list A
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = intersectionNode;
    
    // Create list B
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = intersectionNode;
    
    std::cout << "List A: ";
    printList(headA);
    std::cout << "List B: ";
    printList(headB);
    
    // Test method 1 (hashtable)
    ListNode* result1 = getIntersectionNode_1(headA, headB);
    std::cout << "Intersection (Method 1 - HashTable): ";
    if (result1) {
        std::cout << "Node with value " << result1->val << std::endl;
    } else {
        std::cout << "No intersection" << std::endl;
    }
    
    // Test method 2 (two pointers)
    ListNode* result2 = getIntersectionNode_2(headA, headB);
    std::cout << "Intersection (Method 2 - Two Pointers): ";
    if (result2) {
        std::cout << "Node with value " << result2->val << std::endl;
    } else {
        std::cout << "No intersection" << std::endl;
    }
    
    // Test with non-intersecting lists
    ListNode* headC = new ListNode(1);
    headC->next = new ListNode(2);
    headC->next->next = new ListNode(3);
    
    ListNode* headD = new ListNode(4);
    headD->next = new ListNode(5);
    headD->next->next = new ListNode(6);
    
    std::cout << "\nTesting non-intersecting lists:" << std::endl;
    std::cout << "List C: ";
    printList(headC);
    std::cout << "List D: ";
    printList(headD);
    
    ListNode* result3 = getIntersectionNode_2(headC, headD);
    std::cout << "Intersection: ";
    if (result3) {
        std::cout << "Node with value " << result3->val << std::endl;
    } else {
        std::cout << "No intersection" << std::endl;
    }
    
    return 0;
}



