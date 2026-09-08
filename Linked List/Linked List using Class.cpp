#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// A single linked-list node
class ListNode {
public:
    int data;
    ListNode* next;
    
    ListNode (int data) : data(data), next(nullptr) {};
};

class LinkedList {
private:
	ListNode* head;

public:
	LinkedList () : head (nullptr) {}

//	=================== Insertion ====================

	void push_front (int data) {
        ListNode* newNode = new ListNode(data);
        
        if (head == nullptr) {
            head = newNode;
            return;
        }
        
        newNode->next = head;
        head = newNode;
    }

	void push_middle (int data, int pos) {
		ListNode* newNode = new ListNode (data);

		// Empty list
		if (head == nullptr) {
			cout << "Invalid position!\n";
			delete newNode;
			return;
		}

		// Insert at beginning
		if (pos == 1) {
			newNode->next = head;
			head = newNode;
			return;
		}

		// Find position
		ListNode* ptr = head;

		for (int i = 1; i < pos - 1; i++) {
			ptr = ptr->next;

			if (ptr == nullptr) {
				cout << "Out of bounds!\n";
				delete newNode;
				return;
			}
		}

		// Insert
		newNode->next = ptr->next;
		ptr->next = newNode;
	}

	void push_back (int data) {
		ListNode* newNode = new ListNode (data);

		// Empty list
		if (head == nullptr) {
			head = newNode;
			return;
		}

		// Find last node
		ListNode* ptr = head;

		while (ptr->next != nullptr)
			ptr = ptr->next;

		// Attach new node after last node
		ptr->next = newNode;
	}
	
//	=================== Deletion ====================
	
	void pop_middle (int pos){
	    if (head == nullptr){
	        cout << "empty, can't delete\n";
	        return;
	    }
	    
	    ListNode* ptr = head;
	    
	    if (pos == 1){
	        ptr = ptr->next;
	        delete head;
	        head = ptr;
	        return;
	    }
	    
	    for (int i = 1; i < pos-1; i++) {
	        ptr = ptr->next;
	        
	        if (ptr == nullptr || ptr->next == nullptr) {
				cout << "Out of bounds!\n";
				return;
			}
	    }
	    
	    ListNode* temp = ptr->next;
	    ptr->next = temp->next;
	    delete temp;
	}

	void display () {
		if (head == nullptr) {
			cout << "List is empty!\n";
			return;
		}

		// Find last node
		ListNode* ptr = head;
		while (ptr != nullptr) {
			cout << ptr->data << "->";
			ptr = ptr->next;
		}

		cout << "NULL\n";
	}
};

int main() {
	LinkedList list;

	list.push_front(10);
	list.push_back(70);
	list.push_front(90);
	list.push_back(30);
	list.push_middle(100, 2);

	list.display();

	return 0;
}