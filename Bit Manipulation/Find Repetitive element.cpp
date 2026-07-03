#include <iostream>
#include <vector>
using namespace std;

int findDuplicate (vector<int>& arr) {
    int n = arr.size();
    int res = 0;

    for (int i = 0; i < n - 1; i++) {
        res = res ^ (i + 1) ^ arr[i];
    }
    
    res = res ^ arr[n - 1];
    
    return res;
}

int main() {
	vector<int> arr = {1, 3, 2, 3, 4};
	
	cout << findDuplicate (arr);

	return 0;
}

/*

The array has only one repetitive element. Find the repetitive element.
	- Given an array of size n containing numbers from 1 to n-1.
	- There is exactly one number is repeated, find the duplicate.

Idea: 
	x ^ x = 0
	x ^ 0 = x
	x ^ y = z then x ^ z = y

*/