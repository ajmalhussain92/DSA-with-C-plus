ListNode* reverseList (ListNode* head) {
	ListNode* prev = nullptr;
	ListNode* curr = head;
	ListNode* next = nullptr;

	while (curr != nullptr) {
		next = curr->next;
		curr->next = prev;

		prev = curr;
		curr = next;
	}
	return prev;
}

/*

Actually change the address to point reverse

one traversal, O(n) time and O(1) space


*/