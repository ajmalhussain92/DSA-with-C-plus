#include <iostream>
using namespace std;

class CircularQueue {
private:
	int arr[5];
	int front, rear;

public:
	CircularQueue () {
		front = rear = -1;
	}

	void enqueue (int data) {
		if ((rear + 1) % 5 == front) {
			cout << "Queue Overflow!\n";
			return;
		}

		if (front == -1) front = 0;

		rear = (rear + 1) % 5;
		arr[rear] = data;       // overwrite
	}

	void dequeue () {
		if (front == -1 || rear == -1) {
			cout << "Queue Underflow!\n";
			return;
		}
		
		front = (front + 1) % 5;        // Circular increment
		
		if (front == rear) front = -1, rear = -1;
	}

	void front_ () {
		if (front == -1 || rear == -1) {
			cout << "Empty Stack!\n";
			return;
		}

		cout << arr[front] << endl;
	}

	void back_ () {
		if (front == -1 || rear == -1) {
			cout << "Empty Stack!\n";
			return;
		}

		cout << arr[rear] << endl;
	}

	void show_queue() {
		if (front == -1) {
			cout << "Empty Queue!\n";
			return;
		}
        
		int i = front;
		while (i != rear) {
			cout << arr[i] << " ";
			i = (i + 1) % 5;   		// circular movement
		}
		cout << arr[rear] << "\n"; 	// to include the last element
	}

	bool isEmpty () {
		if (front == -1 || rear == -1)
			return false;
		else
			return true;
	}

	void getSize () {
		if (front == -1 || rear == -1)
			cout << "Size is: " << rear + 1;
		else
			cout << "Size is: " << rear + 1;
	}
};


int main () {
	CircularQueue q1;

	q1.enqueue (90);
	q1.enqueue(80);
	q1.enqueue(30);
	q1.enqueue(40);
	q1.enqueue(20);

	q1.show_queue();
	

	q1.dequeue ();
	q1.show_queue();
	q1.dequeue ();
	q1.show_queue();
	q1.dequeue ();
	q1.show_queue();
	
	q1.front_();
	
	q1.enqueue(10);
	q1.show_queue();
	q1.enqueue(50);
	q1.show_queue();
	
	q1.front_();
	q1.back_();

	return 0;
}