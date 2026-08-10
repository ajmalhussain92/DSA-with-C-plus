#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findPairs (vector<int>& nums, int k) {
	sort (nums.begin(), nums.end());

	int l = 0, r = 1;
	int count = 0;

	while (r < nums.size()) {

		if (l == r) 
			r++;
		else if (nums[r] - nums[l] < k) 
			r++;
		else if (nums[r] - nums[l] > k) 
			l++;
		else {
			count++;

			l++;
			r++;

			while (r < nums.size() && nums[r] == nums[r - 1])		// duplicate-skipping loop
				r++;
		}
	}
	return count;
}

int main () {
	vector<int> nums = {3,1,4,1,3,3,5};
	int k = 2;
	
	cout << findPairs (nums, k);

	return 0;
}

/*

532. K-diff Pairs in an Array

	The problem demands: Unique value pairs

Solution Idea:
	Two Pointers: Same Direction

		int left = 0;
		int right = 0;

----------------------------------------------------
Three Cases at each step:

Case 1:
    difference < k
        r++

Case 2:
    difference > k
            l++

Case 3:
    difference == k
        count++
        l++, r++
        skip duplicates
----------------------------------------------------
In the example: nums = {3,1,4,1,3,3,5}, k = 2

	Index value pairs = 9, but Unique value pairs = 2


*/