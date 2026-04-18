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