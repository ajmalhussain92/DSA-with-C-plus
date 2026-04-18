#include <iostream>
using namespace std;

int main () {
	int num = 6;
	int arr[num] = {16, 13, 7, 2, 1, 12};
	
	int temp;
	for (int i = 0; i < num / 2; i++) {
	    temp = arr[i];
	    arr[i] = arr[num - 1 - i];
	    arr[num - 1 - i] = temp;
	}
	
	for (int x : arr) {
		cout << x << " ";
	}
	
	return 0;
}

/*

Explanation:
	-> Loop from i = 0 to i < num/2. (half)
	-> Swap arr[i] with arr[num - 1 - i].
	-> This effectively reverses the array in-place.

*/
