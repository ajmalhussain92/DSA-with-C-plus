#include <iostream>
using namespace std;

class MyLinkedList {
public:
    int val;
    MyLinkedList* next;

    MyLinkedList() { next = nullptr; }

    MyLinkedList* head = nullptr;

    int get(int index) {
        if (index < 0 || head == nullptr) return -1;

        MyLinkedList* temp = head;
        for (int i = 0; i < index; i++) {
            if (temp == nullptr) return -1;
            temp = temp->next;
        }

        if (temp == nullptr) return -1;
        return temp->val;
    }

    void addAtHead(int val) {
        MyLinkedList* ptr = new MyLinkedList();
        ptr->val = val;

        ptr->next = head;
        head = ptr;
    }

    void addAtTail(int val) {
        MyLinkedList* ptr = new MyLinkedList();
        ptr->val = val;

        if (head == nullptr) { 
            head = ptr;
            return;
        }

        MyLinkedList* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = ptr;
    }

    void addAtIndex(int index, int val) {
        MyLinkedList* ptr = new MyLinkedList();
        ptr->val = val;

        if (head == nullptr) {
            if (index != 0) return;
            ptr->next = head;
            head = ptr;
            return;
        }
        
        if (head->next == nullptr && index == 0) {
            head = ptr;         // rewrite
            return;
        }

        MyLinkedList* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
            if (temp == nullptr)
                return; // index is greater than list length
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }

    void deleteAtIndex(int index) {
        if (head == nullptr || index < 0) return;

        if (index == 0) {
            MyLinkedList* temp = head;
            // head = head->next;
            temp = temp->next;
            delete head;
            head = temp;
            return;
        }

        MyLinkedList* temp = head;
        
        for (int i = 0; i < index - 1; i++) {
            if (temp == nullptr || temp->next == nullptr) return;
            temp = temp->next;
        }
        
        MyLinkedList* del = temp->next;
        cout << "Node before deletion: " << temp->val << endl;
        if (del == nullptr) return; // Added null check to prevent crash
        temp->next = del->next;
        cout << "Deleting node with value: " << del->val << endl;
        delete del;
    }
    
    void display () {
        MyLinkedList* temp = head;
        while (temp != nullptr) {
            cout << temp -> val << " -> ";
            temp = temp->next;
        }
        cout << "null\n";
    }
};


int main() {
    int res;
	MyLinkedList* obj = new MyLinkedList();
	obj -> addAtHead (2);
	obj -> display();
	obj -> addAtIndex (0, 1);
	obj -> display();
    res = obj -> get(1);
    cout << res << endl;

	return 0;
}