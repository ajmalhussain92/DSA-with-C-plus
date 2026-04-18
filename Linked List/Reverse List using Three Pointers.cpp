#include <iostream>
using namespace std;


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

	Node* temp = head;
	while (temp != nullptr) {
		cout << temp -> data << " -> ";
		temp = temp -> next;
	}
	cout << "nullptr\n";
}

Node* reverseList (Node*& head) {
	// Take three pointers
	Node* prev = nullptr;
	Node* curr = head;
	Node* next_node = nullptr;
	
	while (curr != nullptr) {
	    next_node = curr -> next;
	    curr -> next = prev;
	    prev = curr;
	    curr = next_node;
	}
	return prev;		// Now head starts from prev
}

int main() {
	Node* head = nullptr;

	push_front (4, head);
	push_front (5, head);
	push_front (7, head);
	push_front (2, head);
	push_front (9, head);
	display (head);

    head = reverseList (head);
    
	display (head);


	return 0;
}