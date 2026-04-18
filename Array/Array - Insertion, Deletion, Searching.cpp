#include <iostream>
#define size 5
using namespace std;

int arr[size], top = -1;

// Insert @ Beginning
void insert_front (int data) {
    if (top == size - 1) {
        cout << "Overflow! Can't insert.\n";
        return;
    }
    
    top++;
    for (int i = top; i > 0; i--) {     
        arr[i] = arr[i - 1];        // shift elements (i traversal -> right to left)
    }
    arr[0] = data;
}

// Insert @ Middle
void insert_middle (int data) {
    if (top == size - 1) {
        cout << "Overflow! Can't insert.\n";
        return;
    }
    
    if (top == -1) {
        top++;
        arr[top] = data;
        return;
    }
    
    int pos;
    cout << "Enter position (1 to " << top + 1 << "): ";
    cin >> pos;
    
    if (pos - 1 > top || pos == 0) {
        cout << "Out of bounds!\n";
        return;
    }
    
    top++;
    for (int i = top; i > pos - 1; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[pos - 1] = data;        // Insert data
}

// Insert @ End
void insert_back (int data) {
    if (top == size - 1) {
        cout << "Overflow! Can't insert.\n";
        return;
    }
    
    top++;
    arr[top] = data;            // no shift needed
}

// Delete @ Beginning
void delete_front () {
    if (top == -1) {
        cout << "No elements! Can't delete.\n";
        return;
    }
    
    for (int i = 0; i < top; i++) {     
        arr[i] = arr[i + 1];    // shift elements (i traversal -> left to right)
    }
    
    arr[top] = 0;       // 0 means empty in this case
    top--;
}

// Delete @ Middle
void delete_middle () {
    if (top == -1) {
        cout << "No elements! Can't delete.\n";
        return;
    }
    
    int pos;
    cout << "Enter position (1 to " << top + 1 << "): ";
    cin >> pos;
    
    if (pos - 1 > top || pos == 0) {
        cout << "Out of bounds!\n";
        return;
    }
    
    for (int i = pos - 1; i < top; i++) {
        arr[i] = arr[i + 1];
    }
    
    arr[top] = 0;       // 0 means empty in this case
    top--;
}

// Delete @ End
void delete_back () {
    if (top == -1) {
        cout << "No elements! Can't delete.\n";
        return;
    }
    
    arr[top] = 0;
    top--;
}

// Search element
void search_element (int data) {
    if (top == -1) {
        cout << "No elements!\n";
        return;
    }
    
    bool status = true;
    int i = 0;
    for (i = 0; i < top; i++) {
        if (arr[i] == data) {
            status = true;
            break;
        }
    }
    
    if (status)
        cout << "The element " << data << " found at position " << i + 1 << endl;
    else
        cout << "The element " << data << " not found at any position\n";
}

void display () {
    cout << "Array elements: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n";
}

int main () {
    
    insert_front (60);
    insert_front (90);
    insert_back (70);
    insert_front (10);
    insert_front (80);
    display ();
    
    search_element (80);
    
    return 0;
}