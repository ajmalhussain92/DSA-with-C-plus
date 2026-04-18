#include <iostream>
using namespace std;

class Queue {
    private:
    int arr[5];
    int front, rear;
    
    public:
    Queue () {
        front = rear = -1;
    }
    
    // Insert @ Rear (only insertion)
    void enqueue (int data) {
        if (rear == 4) {
            cout << "Queue Overflow!\n";
            return;
        }
        
        if (front == -1) front++;
        
        arr[++rear] = data;
    }
    
    // Delete @ Front (only deletion)
    void dequeue () {
        if (front == -1 || rear == -1) {
            cout << "Queue Underflow!\n";
            return;
        }
        
        front++;
        
        if (front > rear) front = -1, rear = -1;
    }
    
    // Show Front element
    void front_ () {
        if (front == -1 || rear == -1) {
            cout << "Empty Stack!\n";
            return;
        }
        
        cout << arr[front] << endl;
    }
    
    // Show Rear element
    void back_ () {
        if (front == -1 || rear == -1) {
            cout << "Empty Stack!\n";
            return;
        }
        
        cout << arr[rear] << endl;
    }
    
    // Show Queue elements
    void show_queue () {
        if (front == -1 || rear == -1) {
            cout << "Empty Queue!\n";
            return;
        }
        
        for (int i = front; i < rear + 1; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    
    // Check if Queue is empty
    bool isEmpty () {
        if (front == -1 || rear == -1) 
            return false;
        else 
            return true;
    }
    
    // Get the Size of a Queue
    void getSize () {
        if (front == -1 || rear == -1)
            cout << "Size is: " << rear + 1;
        else 
            cout << "Size is: " << rear + 1;
    }
};


int main () {
	Queue q1;
	
	q1.show_queue();
	q1.enqueue (90);
	q1.show_queue();
	q1.enqueue (70);
	q1.show_queue();
	
	
	q1.front_();
	q1.back_();

	return 0;
}

/* Important Point:

	1.) No actual removal of data
		-> You do NOT need to delete or shift elements.
		-> Just move front forward to logically remove the element.
		-> The actual data remains in the array but is no longer considered part of the queue.
		-> Overwriting this position on subsequent enqueues is fine.

	Drwaback of a Simple Non-Circular Queue:
		If the element is deleted, there is unused space at the front.

*/