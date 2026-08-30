#include <iostream>
#include <vector>
using namespace std;

int findKthPositive (vector<int>& arr, int k) {

	int low = 0;
	int high = arr.size() - 1;

	while (low <= high) {

		int mid = low + (high - low) / 2;

		int missing = arr[mid] - (mid + 1);

		if (missing < k) 
			low = mid + 1;

		else 
			high = mid - 1;
	}

	return low + k;
}

int main () {
	vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    cout << findKthPositive (arr, k);

	return 0;
}

/*

Kth Missing Positive Number in a Sorted Array:
Idea: Binary Search on the answer/index

If there were no missing numbers
    arr[i] = i + 1

So the number of missing positive integers up to arr[i] is:
    missing(i) = arr[i] - (i + 1)

For:
    arr = [2,3,4,7,11]
    k = 5

We have:
    index       0  1  2  3  4
    arr         2  3  4  7 11
    missing     1  1  1  3  6

*/