// ======== slow-and-fast pointer (Floyd's) technique ========

ListNode* middleNode(ListNode* head) {
	ListNode* slow = head;
	ListNode* fast = head;

	while (fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

// ======== 2 pass technique ========

ListNode* middleNode(ListNode* head) {
    ListNode* ptr = head;
    
    int n = 0;
    
    while(ptr != nullptr){
        ptr = ptr->next;
        n++;
    }
    
    ptr = head;
    for (int i = 1; i <= n/2; i++) 
        ptr = ptr->next;
    
    return ptr;
}