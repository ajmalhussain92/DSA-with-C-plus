#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;


double findMedianSortedArrays (vector<int>& nums1, vector<int>& nums2) {
	if (nums1.size() > nums2.size())
		return findMedianSortedArrays (nums2, nums1);

	int n = nums1.size();
	int m = nums2.size();

	int total = n + m;
	int half = total / 2;

	int low = 0;
	int high = n;

	while (low <= high) {

		int cutA = (low + high) / 2;
		int cutB = half - cutA;

		int aL = (cutA == 0) ? INT_MIN : nums1[cutA - 1];
		int aR = (cutA == n) ? INT_MAX : nums1[cutA];

		int bL = (cutB == 0) ? INT_MIN : nums2[cutB - 1];
		int bR = (cutB == m) ? INT_MAX : nums2[cutB];

		if (aL <= bR && bL <= aR) {

			// Odd number of elements
			if (total % 2 == 1)
				return min(aR, bR);

			// Even number of elements
			return ((double)max(aL, bL) + min(aR, bR)) / 2.0;
		}

		else if (aL > bR) {
			high = cutA - 1;
		}

		else {
			low = cutA + 1;
		}
	}

	return -1;
}

int main () {
	vector<int> a = {1, 3};
	vector<int> b = {2, 4};

	cout << findMedianSortedArrays (a, b);

	return 0;
}


/*

Median of Two Sorted Arrays:
	Binary Search on Partition + Median logic

-------------------------------------------------------------------------
Note: Array must be sorted!

	Even total number of elements ? median is the average of the two middle elements.
	Odd total number of elements ? median is the single middle element.
-------------------------------------------------------------------------
Time	= O(log(min(n + m))) 		or	 simply O(log n)
Space	= O(1)

*/