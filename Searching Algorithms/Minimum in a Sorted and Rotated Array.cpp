#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int findMinimum (vector<int>& arr) {

    int lo = 0;
    int hi = arr.size() - 1;

    while (lo < hi) {
        if (arr[lo] < arr[hi])
            return arr[lo];

        int mid = lo + (hi - lo) / 2;

        if (arr[mid] > arr[hi]) {
            // Minimum is definitely to the right of mid
            lo = mid + 1;
        }
        else {
            // Minimum is at mid or to the left
            hi = mid;
        }
    }

    return arr[lo];
}

int main () {
	vector<int> arr = {5, 6, 7, 8, 9, 10, 2, 3};

	cout << findMinimum (arr) << endl;

	return 0;
}

/*

Think:

mid > hi ? minimum is RIGHT.
mid <= hi ? minimum is LEFT or MID.

Time: O(log n)
Space: O(1).

*/