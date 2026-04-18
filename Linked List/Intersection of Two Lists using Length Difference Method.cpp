#include <iostream>
using namespace std;

// Node structure
struct Node {
	int data;
	Node* next;
};

void push_front (int data, Node*& head) {
	Node* ptr = new Node ();
	ptr-> data = data;
	ptr-> next = nullptr;

	if (head == nullptr) {
		head = ptr;
		return;
	}
	ptr -> next = head;
	head = ptr;
}


void display (Node*& head) {
	if (head == nullptr) {
		cout << "List is empty\n";
		return;
	}

	Node* t1 = head;
	while (t1 != nullptr) {
		cout << t1 -> data << " -> ";
		t1 = t1 -> next;
	}
	cout << "nullptr\n";
}

Node* getIntersectionNode (Node*& headA, Node*& headB) {
	int n = 0, m = 0;

	Node* t1 = headA;
	Node* t2 = headB;

	// Count lengths
	while (t1 != nullptr) {
		n++;
		t1 = t1 -> next;
	}

	while (t2 != nullptr) {
		m++;
		t2 = t2 -> next;
	}

	// Reset pointers
	t1 = headA;
	t2 = headB;

	int d = abs(n - m);

	// Advance longer list
	if (n > m) {
		while (d--) t1 = t1->next;
	} else {
		while (d--) t2 = t2->next;
	}

	// Traverse together
	while (t1 != nullptr && t2 != nullptr) {
		if (t1 == t2)   // ADDRESS comparison
			return t1;

		t1 = t1->next;
		t2 = t2->next;
	}

	return nullptr;
}

int main () {
	cout<<"Linked List Program\n";
	cout<<"--------------------------------\n";

	Node* headA = nullptr;
	Node* headB = nullptr;

	// push_front (90, headA);
	// push_front (70, headA);
	// push_front (10, headA);

	// push_front (90, headB);
	// push_front (70, headB);
	// push_front (20, headB);
	// push_front (50, headB);
	// push_front (40, headB);

	Node* common = new Node{100, nullptr};
	common->next = new Node{200, nullptr};

	headA->next->next = common;   // attach to list A
	headB->next->next->next = common; // attach to list B



// 	display (headA);
// 	display (headB);

	Node* res = getIntersectionNode (headA, headB);

	if (res != nullptr)
		cout << "Intersection node = " << res->data << endl;
	else
		cout << "No Intersection node found!" << endl;

	return 0;
}