#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int searchInRotated (vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (arr[mid] == target)
			return mid;

		// Determine which half is sorted
		if (arr[low] <= arr[mid]) {

			// Left half is sorted
			if (arr[low] <= target && target < arr[mid])
				high = mid - 1;
			else
				low = mid + 1;

		} else {

			// Right half is sorted
			if (arr[mid] < target && target <= arr[high])
				low = mid + 1;
			else
				high = mid - 1;
		}
	}

	return -1;
}

int main () {
	vector<int> arr = {6, 8, 9, 12, 2, 3, 4, 5};
    int key = 2;
    
    cout << searchInRotated (arr, key) << endl;

	return 0;
}
