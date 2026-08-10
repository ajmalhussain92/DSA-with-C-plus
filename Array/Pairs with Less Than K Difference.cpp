#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countPairs (vector<int>& arr, int k) {
	sort (arr.begin(), arr.end());

	int ans = 0;

	int l = 0;
	for (int r = 1; r < arr.size(); r++) {
		while (l < r && arr[r] - arr[l] >= k)
			l++;

		ans +=  r - l;
	}

	return ans;
}

int main () {
	vector<int> arr = {1, 10, 4, 2};
	int k = 3;
	
	cout << countPairs (arr, k);

	return 0;
};

/*

Examples:

Input : arr[] = [1, 10, 4, 2], k = 3
Output : 2
Explanation: We have an array arr[] = [1, 10, 4, 2] and k = 3 We can make only two pairs with a difference of less than 3.
			 (1, 2) and (4, 2). So, the answer is 2.

Input : arr[] = [2, 3, 4], k = 5
Output : 3
Explanation: For the given array arr[] = [2, 3, 4] and k = 5, there are 3 valid pairs where the absolute difference between the pair's elements is less than 5.
			 These pairs are (2, 3), (2, 4), and (3, 4). Hence, the output is 3.


Complexity
	Sorting 		= O(n log n)
	Two pointers 	= O(n)

Overall: O(n log n)
----------------------------------------------------
This is a classic pattern:

	Absolute difference  = think sorting.
	Sorted array = think two pointers.
	Once arr[right] - arr[left] >= k, every element beyond right will also fail (because the array is sorted). 
	That's the monotonic property that makes the two-pointer solution linear after sorting.

----------------------------------------------------
Solution Idea:
	Two Pointers: Same Direction

		int left = 0;
		int right = 0;

*/
