

// Recursive - O(n+m) Time, O(n+m) Space ======================================
ListNode* mergeTwoLists (ListNode* list1, ListNode* list2) {
	if (list1 == nullptr || list2 == nullptr)
		return (list1 == nullptr) ? list2 : list1;

	if (list1->val <= list2->val) {
		list1->next = mergeTwoLists (list1->next, list2);
		return list1;
	}
	else {
		list2->next = mergeTwoLists (list1, list2->next);
		return list2;
	}
}


// Dummy Head + Tail Pointer Pattern - O(n+m) Time, O(1) Space ===============
ListNode* mergeTwoLists (ListNode* list1, ListNode* list2) {
	ListNode* dummy = new ListNode(-1);
	ListNode* curr = dummy;
	
	while (list1 != nullptr || list2 != nullptr) {
	    
	    if (list1->val <= list2->val) {
	        curr->next = list1;
	        list1 = list1->next;
	    }
	    else {
	        curr->next = list2;
	        list2 = list2->next;
	    }
	    
	    curr = curr->next;
	}
	
	// Attach the remaining list
	curr->next = (list1 != nullptr) ? list1 : list2;
	
	return (dummy->next);
}

/*

dummy is our permanent starting anchor.

curr is our moving tail.




*/