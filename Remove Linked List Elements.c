struct ListNode* removeElements(struct ListNode* head, int val) {
    // 1) Create a dummy node to handle cases where the head itself may be removed.
    struct ListNode dummy;   
    dummy.val = -1;          // Assign a temporary value (not important)
    dummy.next = head;       // Dummy points to the current head

    // 2) Use a pointer *current* to traverse from the dummy node.
    struct ListNode* current = &dummy;

    // 3) Continue until there are no more nodes to check.
    while (current->next != NULL) {
        // 4) If the next node has the target value, skip/remove it.
        if (current->next->val == val) {
            struct ListNode* nodeToRemove = current->next;
            current->next = current->next->next;
            // free(nodeToRemove);  // Uncomment if you want to free the removed node from memory.
        } else {
            // 5) Otherwise, move 'current' to the next node.
            current = current->next;
        }
    }

    // 6) Return the updated list starting from dummy.next (new head).
    return dummy.next;
}
