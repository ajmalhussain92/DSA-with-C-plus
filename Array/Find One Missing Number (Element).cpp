#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int missingNum (vector<int>& arr) {
	int size = arr.size();      // current array size
	int n = size + 1;           // original size

	int xor1 = 0, xor2 = 0;

	// XOR all array elements
	for (int x : arr)
		xor1 ^= x;

	// XOR all numbers from 1 to n
	for (int i = 1; i <= n; i++) 
		xor2 ^= i;

	return xor1 ^ xor2;
}

int main () {
	vector<int> arr = {8, 2, 4, 5, 3, 7, 1};

	cout << missingNum (arr);

	return 0;
}

/*

Note:
    XOR works for only one missing number
    XOR works for only when the array contains all integers from 1 to n

Examples:
    arr = [1 2 3 4 6]       XOR works
    arr = [3 4 6 8 9]       XOR does not work

Idea:
	x ^ x = 0
	x ^ y = z then x ^ z = y

*/