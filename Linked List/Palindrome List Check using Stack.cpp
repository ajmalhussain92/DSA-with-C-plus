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

bool isPlaindrome (Node*& head) {
    Node* temp = head;
    while (temp != nullptr) {
        s.push (temp -> data);
        temp = temp -> next;
    }
    
    Node* ptr = head;
    while (ptr != nullptr) {
        if (ptr->data == s.top()){
            ptr = ptr -> next;
            s.pop();
        }
        else {
            return false;
        }
    }
    return true;
}

int main() {
    Node* head = nullptr;
    
    push_front (1, head);
    push_front (2, head);
    push_front (3, head);
    push_front (2, head);
    push_front (1, head);
    display (head);
    
    bool res = isPlaindrome (head);
    
    if (res == true) 
        cout << "List is palindrome";
    else
        cout << "List is not palindrome";
    

    return 0;
}