// ======== slow-and-fast pointer (Floyd's) technique ========

bool detectCycle (Node* head) {
	Node* slow = head;
	Node* fast = head;

	bool isCycle = false;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) {
			isCycle = true;
			break;
		}
	}

	if (!isCycle) return false;

	slow = head;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}