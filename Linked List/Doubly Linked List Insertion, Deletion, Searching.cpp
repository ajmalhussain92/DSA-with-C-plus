#include <iostream>
using namespace std;

// ----- Doubly linked lists

struct Node {
    Node* prev;
    int data;
    Node* next;
    
    Node () {
        prev = nullptr;
        next = nullptr;
    }
};

// Insert @ Beginning
void push_front (Node*& head, int data) {
    Node* ptr = new Node ();    // Node constructor initializes prev and next to nullptr
    ptr->data = data;
    
    if (head == nullptr) {      // if empty list
        head = ptr;
        return;
    }
    
    ptr->next = head;
    head->prev = ptr;
    head = ptr;
}

// Insert @ End
void push_back (Node*& head, int data) {
    Node* ptr = new Node ();    // Insert node // Node constructor initializes prev and next to nullptr
    ptr->data = data;
    
    if (head == nullptr) {      // if empty list, then insert @ beginning
        head = ptr;
        return;
    }
    
    Node* temp = head;          // Traversal node
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = ptr;           // Link last node to new node
    ptr->prev = temp;           // Link new node back to last node
}

// Insert @ Middle
void push_middle (Node*& head, int data) {
    Node* ptr = new Node ();    // Insert node // Node constructor initializes prev and next to nullptr
    ptr->data = data;
    
    if (head == nullptr) {      // if empty list, then insert @ beginning
        cout << "Empty list! Inserting at beginning.\n";
        head = ptr;
        return;
    }
    
    int pos;
    cout << "Enter position: ";
    cin >> pos;
    
    if (pos <= 0) {             // Invalid pos? then return, do nothing
        cout << "Invalid position!\n";
        return;
    }
    
    if (pos == 1) {             // insert @ beginning, if pos = 1
        ptr->next = head;       // Link old head back to new node
        head = ptr;
        return;
    }
    
    Node* temp = head;
    
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
        if (temp == nullptr) {
            cout << "Out of bounds! Can't insert.\n";
            return;
        }
    }
    ptr->next = temp->next;     // Link new node to its next node
    temp->next = ptr;           // Link previous node to new node
    ptr->prev = temp;           // Link new node back to its previous node
}

// Delete @ Beginning
void pop_front (Node*& head) {
    if (head == nullptr) {      // if empty list, simply return
        cout << "Empty list! Can't delete.\n";
        return;
    }
    
    Node* temp = head;
    
    // temp = temp->next;       // 1st method
    // delete head;
    // head = temp;
    
    head = head->next;          // 2nd method
    delete temp;
    
    if (head != nullptr) head->prev = nullptr;
}

// Delete @ Middle
void pop_middle (Node*& head) {
    if (head == nullptr) {      // if empty list, simply return
        cout << "Empty list! Can't delete.\n";
        return;
    }
    
    // if list has only one node (head)
    if (head->next == nullptr) {
        cout << "Only node (head), deleted.\n";
        delete head;
        head = nullptr;
        return;
    }
    
    int pos;
    cout << "Enter position: ";
    cin >> pos;
    
    if (pos <= 0) {             // Invalid pos? then return, do nothing
        cout << "Invalid position!\n";
        return;
    }
    
    Node* temp = head;          // Traversal node
    if (pos == 1) {             // Delete @ beginning, if pos = 1
        head = head->next;
        head->prev = nullptr;
        delete temp;
        return;
    }
    
    // Move the node before the target position
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
        if (temp->next == nullptr) {
            cout << "Position out of range! Can't delete.\n";
            return;
        }
    }
    
    Node* del = temp->next;
    temp->next = del->next;
    if (del->next != nullptr) {     // List is Doubly here, so maintain 'prev' of next node if any
        del->next->prev = temp;
    }
    
    delete del;
}

// Delete @ End
void pop_back (Node*& head) {
    if (head == nullptr) {          // if empty list, simply return
        cout << "Empty list! Can't delete.\n";
        return;
    }
    
    // if list has only one node
    if (head->next == nullptr) {
        delete head; 
        head = nullptr;             // Important!
        return;
    }
    
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    
    delete temp->next;
    temp->next = nullptr;
}

// Searching
void search (Node* head) {          // We are not modifying head, so, "Node*&" not required
    if (head == nullptr) {          // if empty list, simply return
        cout << "Empty list!\n";
        return;
    }
    
    int val;
    cout << "Enter the value: ";
    cin >> val;
    
    int pos = 1;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == val) {
            cout << "The value " << val << " found at position " << pos << " in the list.\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "The value " << val << " not found in the list.\n";
}

// Display Forward
void display (Node* head) {
    if (head == nullptr) {
        cout << "Empty list!\n";
        return;
    }
    
    cout << "NULL -> ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Display Backward
void display_reverse(Node* head) {
    if (head == nullptr) {
        cout << "Empty list!\n";
        return;
    }

    Node* temp = head;

    // Step 1: Move to tail
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Step 2: Traverse backward
    cout << "NULL <- ";
    while (temp != nullptr) {
        cout << temp->data << " <- ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}

int main () {
    Node* head = nullptr;

    push_back (head, 70);
    push_back (head, 10);
    push_back (head, 40);
    push_back (head, 80);
    push_back (head, 30);
    
    display (head);
    display_reverse (head);
    
    return 0;
}