#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int partition (vector<int>& nums, int left, int right) {
    int pivot = nums[right];

    int i = left;

    for (int j = left; j < right; j++) {
        if (nums[j] <= pivot) {
            swap(nums[i], nums[j]);
            i++;
        }
    }

    swap(nums[i], nums[right]);

    return i;
}

int quickSelect (vector<int>& nums, int left, int right, int target) {
    int pivotIndex = partition(nums, left, right);

    if (pivotIndex == target)
        return nums[pivotIndex];

    if (pivotIndex < target)
        return quickSelect(nums, pivotIndex + 1, right, target);

    return quickSelect(nums, left, pivotIndex - 1, target);
}

int findKthLargest (vector<int>& nums, int k) {
    int n = nums.size();

    // kth largest -> index in ascending order
    int target = n - k;

    return quickSelect (nums, 0, n - 1, target);
}

int main () {
	vector<int> nums = {3, 2, 1, 5, 6, 4};
	int target = 2;

	cout << findKthLargest (nums, target);
	
	return 0;
}

/*

215. Kth Largest Element in an Array

Quickselect is basically Quicksort where we only recurse into the side containing the answer

---------------------------------------------------------------------------
QuickSort:
	quickSort(left, pivot - 1);
	quickSort(pivot + 1, right);

---------------------------------------------------------------------------
Quickselect:
	if (pivotIndex < target)
	    quickSelect(pivot + 1, right, target);
	else
	    quickSelect(left, pivot - 1, target);

---------------------------------------------------------------------------
QuickSort = partition + both sides
QuickSelect = partition + one side

*/