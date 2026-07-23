#include <iostream>
#include <vector>
using namespace std;

bool increasingTriplet (vector<int>& nums) {

	int first = INT_MAX;
	int second = INT_MAX;

	for (int num : nums) {

		if (num <= first)
			first = num;

		else if (num <= second)
			second = num;

		else
			return true; // num > second
	}

	return false;
}

int main() {
	vector<int> arr = {1,2,3,4,5};

	cout << increasingTriplet (arr) << endl;
	
	return 0;
}

/*

The intended O(n) solution

	first = smallest number seen so far
	second = smallest number greater than first


Input: nums = [1,2,3,4,5]
Output: true

Input: nums = [5,4,3,2,1]
Output: false

Input: nums = [2,1,5,0,4,6]
Output: true

*/