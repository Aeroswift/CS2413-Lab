struct ListNode* reverseList(struct ListNode* head) {
    // 1) We use three pointers: prev, curr, and next.
    //    'prev' will eventually become the new head after reversal.
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;

    // 2) Traverse the list until curr is NULL (end of list).
    while (curr != NULL) {
        // 3) Save the next node before breaking the link.
        next = curr->next;
        
        // 4) Reverse the current node's pointer to point to the previous node.
        curr->next = prev;
        
        // 5) Move 'prev' and 'curr' one step forward.
        prev = curr;
        curr = next;
    }

    // 6) At the end, 'prev' is the new head of the reversed list.
    return prev;
}
