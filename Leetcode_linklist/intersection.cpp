ListNode *getIntersectionNode_1(ListNode *headA, ListNode *headB) {
    /*That method uses hashtable to check if something in B occured in A*/
    unordered_set<ListNode*> visited;
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
    //A = a+m, B = b+m, A+b = a+B, thet will reach the same point at te same time.
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



