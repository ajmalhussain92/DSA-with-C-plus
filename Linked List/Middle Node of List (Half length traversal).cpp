#include <iostream>
#include <stack>
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

Node* middleNode (Node*& head) {
	int n = 0;          // Size of list
	int i = 1;
	
	Node* temp = head;

	// Find the size of the list
	while (temp != nullptr) {
		n++;
		temp = temp -> next;
	}

	// Reset temp for second traversal
	temp = head;
	while (i < n) {
		temp = temp -> next;	// Half length traversal 
		if (i == (n / 2)) {
			break;      // Stops @ half length of list
		}
		i++;
	}
	return temp;
}

int main() {
	Node* head = nullptr;

	push_front (4, head);
	push_front (5, head);
	push_front (3, head);
	push_front (7, head);
	push_front (2, head);
	push_front (9, head);
	display (head);

	Node* mid_node = middleNode (head);
	
	cout << "Middle node found: " << mid_node -> data;
    

	return 0;
}