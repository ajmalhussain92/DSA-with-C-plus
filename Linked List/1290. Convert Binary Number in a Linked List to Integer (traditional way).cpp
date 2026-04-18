#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

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

int getDec (Node*& head) {
    Node* temp = head;
	while (temp != nullptr) {
		s.push (temp -> data);
		temp = temp -> next;
	}

	int dec = 0;    // placeholder
	int pwr = 0;
	int n = s.size();

	for (int i = 1; i <= n; i++) {
		dec = dec + s.top() * pow(2, pwr);

		s.pop();
		pwr++;
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

/*

	"dec = dec * base + current->val" works for converting numbers from any base to decimal

*/