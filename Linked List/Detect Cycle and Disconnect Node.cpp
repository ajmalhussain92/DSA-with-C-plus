// ======== slow-and-fast pointer (Floyd's) technique ========

bool detectCycleAndRemove (Node* head) {
	Node* slow = head;
	Node* fast = head;

	bool isCycle = false;
    
    // Cycle detection part
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) {
			isCycle = true;
			break;
		}
	}

	if (!isCycle) return false;
    
    // Find cycle starting node
	slow = head;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	
	// 3. Find last node of cycle
    Node* ptr = slow;

    while (ptr->next != slow) 
        ptr = ptr->next;


    // 4. Break the cycle
    ptr->next = nullptr;

    return true;
}