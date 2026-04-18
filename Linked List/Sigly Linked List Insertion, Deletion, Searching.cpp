#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

// Insert @ Beginning
void push_front (int data, Node*& head) {
	Node* ptr = new Node ();
	ptr -> data = data;
	ptr -> next = nullptr;

	if (head == nullptr) {
		head = ptr;
		return;
	}

	ptr -> next = head;
	head = ptr;
}

// Insert @ Middle
void push_middle (Node*& head) {
    Node* ptr = new Node ();    // Insert node
    ptr -> next = nullptr;
    int x;
    
    if (head == nullptr) {
        cout << "Empty list!\n";
        cout << "Enter data to insert (at first): ";
        cin >> x;
        ptr -> data = x;
        head = ptr;
        head -> next = nullptr;
        return;
    }
    
    int pos;
    cout << "Enter position: ";
    cin >> pos;
    if (pos <= 0) {
        cout << "Invalid position!\n";
        return;
    }
    
    cout << "Enter data: ";
    cin >> x;
    ptr -> data = x;
    
    // Insert at beginning (if pos = 1)
	if (pos == 1) {
		ptr -> next = head;
		head = ptr;
		return;
	}
    
    Node* temp = head;          // Traversal node
    for (int i = 1; i < pos - 1; i++) {
        temp = temp -> next;
        
        if (temp == nullptr) {
            cout << "Out of bounds!\n";
            delete ptr;         // avoid memory leak
            return;
        }
    }
    // Insert node
    ptr -> next = temp -> next;
    temp -> next = ptr;
}

// Insert @ End
void push_back(int data, Node*& head) {
	Node* temp;     // Traversal node
	Node* ptr;      // Insert node

	ptr = new Node();
	ptr -> data = data;
	ptr -> next = nullptr;

	if (head == nullptr) {
		head = ptr;
		return;
	}

	temp = head;
	while (temp -> next != nullptr) {
		temp = temp -> next;
	}
	
	// Insert at the end
	temp -> next = ptr;
}

// Delete @ Beginning
void pop_front (Node*& head) {
    if (head == nullptr) {
        cout << "Empty list! Can't delete.\n";
        return;
    }
    
    Node* temp = head;          // Traversal node
    temp = temp -> next;		// next node after head
    
    delete head;				// Delete first node
    head = temp;				// Now Second node is Head node
}

// Delete @ Middle
void pop_middle (Node*& head) {
    if (head == nullptr) {
        cout << "Empty list! Can't delete.\n";
        return;
    }
    
    int pos;
    cout << "Enter position: ";
    cin >> pos;
    
    if (pos <= 0) {
        cout << "Invalid position!\n";
        return;
    }

    Node* temp = head;
    if (pos == 1) {
        temp = temp -> next;
        delete head;
        head = temp;
        return;
    }
    
    for (int i = 1; i < pos - 1; i++) {
        temp = temp -> next;
        
        if (temp == nullptr || temp->next == nullptr) {
	        cout << "Position out of range!\n";
	        return;
    	}
    }
    
    Node* del = temp -> next;
    temp -> next = del -> next;
    delete del;
}

// Delete @ End
void pop_back (Node*& head) {
    if (head == nullptr) {
        cout << "Empty list! Can't delete.\n";
        return;
    }
    
    if (head -> next == nullptr) {					// List has only one node (head)
        delete head;
        head = nullptr;
        return;
    }
    
    Node* temp = head;
    while (temp -> next -> next != nullptr) {		// Traverse to second last node
        temp = temp -> next;
    }
    
    delete temp -> next;
    temp -> next = nullptr;
}

// Display List
void display (Node*& head) {
	if (head == nullptr) {
		cout << "Empty list!\n";
		return;
	}

	Node* temp = head;
	while (temp != nullptr) {
		cout << temp -> data << " -> ";
		temp = temp -> next;
	}
	cout << "nullptr\n";
}

int main () {
	Node* head = nullptr;
	
	display (head);
	push_middle (head);
	push_back (90, head);
	push_back (30, head);
	display (head);
	push_middle (head);
	display (head);
	push_middle (head);
	display (head);
	push_middle (head);
	display (head);

	return 0;
}