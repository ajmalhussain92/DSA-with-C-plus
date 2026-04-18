#include <iostream>
#include <stack>
using namespace std;

int main () {
	int num = 5;
	int arr[num] = {5, 4, 9, 3, 7};
	stack<int> s;
	
	// Push all elements to the stack
	for (int i = 0; i < num; i++) {
	    s.push(arr[i]);
	}
	
	// Updates elements of the array
	for (int i = 0; i < num; i++) {
	    arr[i] = s.top();
	    s.pop();
	}
	
	for (int x : arr) {
		cout << x << " ";
	}
	
	return 0;
}