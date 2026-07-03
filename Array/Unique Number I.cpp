#include <iostream>
#include <vector>
using namespace std;

int findUnique (vector<int> &arr) {
	int res = 0;

	for (int x : arr)
		res ^= x;

	return res;
}



int main () {
	vector<int> arr = {2, 30, 2, 15, 20, 30, 15};

	cout << findUnique (arr);
}


/*

Unique Number I

	-> Find single unique element.
	-> Simply XOR all array elements.

*/