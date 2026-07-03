#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int missingNum (vector<int>& arr) {
    int n = arr.size() + 1;
    
    int xor1 = 0;
    int xor2 = 0;

    // XOR all array elements
    for (int i = 0; i < n - 1; i++) {
        xor1 ^= arr[i];
    }

    // XOR all numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        xor2 ^= i;
    }

    return xor1 ^ xor2;
}

int main () {
	vector<int> arr = {8, 2, 4, 5, 3, 7, 1};

	cout << missingNum (arr);

	return 0;
}

/*

The array has only one repetitive element. Find the repetitive element.

Idea:
	x ^ x = 0
	x ^ y = z then x ^ z = y

*/