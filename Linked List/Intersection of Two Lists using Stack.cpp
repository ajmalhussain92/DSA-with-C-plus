#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
};

ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
	stack<ListNode*> s1, s2;
	
	ListNode* currA = headA;
	ListNode* currB = headB;

	// Push all nodes of list A onto stack s1
	while (currA != NULL) {
		s1.push(currA);
		currA = currA->next;
	}

	// Push all nodes of list B onto stack s2
	while (currB != NULL) {
		s2.push(currB);
		currB = currB->next;
	}

	ListNode* intersection = NULL;
	// Compare the top nodes of both stacks
	while (!s1.empty() && !s2.empty()) {
		if (s1.top() == s2.top()) {
			intersection = s1.top(); // Update intersection
			s1.pop();
			s2.pop();
		} else {
			break;
		}
	}

	return intersection; // Returns NULL if no intersection
}


int main () {
    ListNode* headA = nullptr;
    ListNode* headB = nullptr;
    
    return 0;
}