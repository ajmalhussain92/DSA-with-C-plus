#include <iostream>
#include <vector>
using namespace std;

// Kadane's Algorithm - O(n) Time and O(1) Space
int Kadanes (vector<int>& arr) {
	int curr = arr[0];
	int ans = arr[0];

	for (int i = 1; i < arr.size(); i++) {
		curr = max (arr[i], curr + arr[i]);
		ans = max (ans, curr);
	}
	
	return ans;
}

int main () {
	vector<int> arr = {4, -3, 2, 5, -6};

	cout << Kadanes (arr);

	return 0;
};

/*

Kadane's Algorithm
    Kadane's algorithm is designed to solve the Maximum Subarray Sum problem in the array.
    The core Idea:
        At every index, decide whether to extend the previous subarray or start a new one.

    Maximum Subarray Sum problem is also known as the Maximum Segment Sum problem.
---------------------------------------------------------------------------------
curr = max (arr[i], curr + arr[i])
	It is the Best End of a subarray at index i.
	It is the Maximum Sum of a subarray at index i.

Example 1:
	arr 			= {4, -3, 2, 5, -6}
	bestEnd (curr) 	= {4, 1, 3, 8, 2}

Example 2:
	arr 			= {-2, 1, -3, 4, -1, 2, 1}
	bestEnd (curr) 	= {-2, 1, -2, 4, 3, 5, 6}

Finally:
	ans = max (ans, curr)
		= max (ans, 6)
		= 6
---------------------------------------------------------------------------------
Complexity:
    Time Complexity: O(n)
    Space Complexity: O(1) (only two variables are needed)


*/