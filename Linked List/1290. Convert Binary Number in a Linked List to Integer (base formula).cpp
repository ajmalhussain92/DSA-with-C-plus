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

int getDec (Node*& head) {
    int dec = 0;
    
    Node* temp = head;
	while (temp != nullptr) { 
		dec = dec * 2 + temp -> data;   // base = 2
		temp = temp -> next;
	}

	return dec;
}


int main() {
	Node* head = nullptr;

	push_front (1, head);
	push_front (0, head);
	push_front (1, head);

	int res = getDec (head);

	cout <<res;

	return 0;
}