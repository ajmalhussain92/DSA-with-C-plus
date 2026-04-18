#include <iostream>
#include <stack>
using namespace std;

// stack
stack<int> s;

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

bool isPalindrome(Node*& head) {
	if (!head || !head->next)
		return true;

	// Find middle
	Node* slow = head;
	Node* fast = head;

	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	// Reverse second half
	Node* prev = nullptr;
	while (slow) {
		Node* nextNode = slow->next;
		slow->next = prev;
		prev = slow;
		slow = nextNode;
	}

	// Compare both halves
	Node* left = head;
	Node* right = prev;

	while (right) {
		if (left->data != right->data)
			return false;
		left = left->next;
		right = right->next;
	}
	return true;
}

int main() {
	Node* head = nullptr;

	push_front (1, head);
	push_front (2, head);
	push_front (2, head);
	push_front (2, head);
	push_front (1, head);
	display (head);

	bool res = isPalindrome (head);

	if (res == true)
		cout << "List is palindrome";
	else
		cout << "List is not palindrome";


	return 0;
}