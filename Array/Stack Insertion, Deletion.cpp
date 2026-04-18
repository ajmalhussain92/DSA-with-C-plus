#include <iostream>
using namespace std;

class Stack {
    private:
    int arr[5];
    int top;
    
    public:
    Stack () {
        top = -1;
    }
    
    // Insert @ Top (only insertion)
    void push (int data) {
        if (top == 4) {
            cout << "Overflow!\n";
            return;
        }
        
        arr[++top] = data;
    }
    
    // Delete @ Top (only deletion)
    void pop () {
        if (top == -1) {
            cout << "Underflow!\n";
            return;
        }
        
        top--;
    }
    
    // Show Top element
    void peek () {
        if (top == -1) {
            cout << "Empty Stack!\n";
            return;
        }
        
        cout << arr[top] << endl;
    }
    
    // Show Stack elements
    void show_stack () { 
        if (top == -1) { 
            cout << "Empty Stack!\n";
            return;
        } 
        
        for (int i = 0; i < top + 1; i++) { 
            cout << arr[i] << " ";
        } 
    } 
    
    // Check if Stack is empty
    bool isEmpty () {
        if (top == -1) 
            return false;
        else 
            return true;
    } 
};


int main () {
	Stack s1;
	s1.pop();

	return 0;
}