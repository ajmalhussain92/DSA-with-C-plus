

Node* cloneLinkedList (Node* head) {
	if (head == nullptr) return nullptr;

	Node* newHead = new Node(head->data);

	unordered_map<Node*, Node*> mp;
	mp[head] = newHead;

	Node* oldTemp = head->next;
	Node* newTemp = newHead;

	while (oldTemp != nullptr) {
		Node* copyNode = new Node(oldTemp->data);
		newTemp->next = copyNode;

		mp[oldTemp] = copyNode;

		oldTemp = oldTemp->next;
		newTemp = newTemp->next;
	}

	oldTemp = head;
	newTemp = newHead;

	while (oldTemp != nullptr) {
		newTemp->random = mp[oldTemp->random];

		oldTemp = oldTemp->next;
		newTemp = newTemp->next;
	}

	return newHead;
}

/*

Clone List with Next and Random, or Copy List with Next and Random

*/