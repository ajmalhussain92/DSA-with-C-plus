#include <iostream>
using namespace std;

int partition (int arr[], int left, int right) {
    int pivot = arr[right];     // choose the last element as pivot
    
    int i = left - 1;           // pointer for greater element
    
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap (arr[i], arr[j]);
        }
    }
    
    // Place the pivot after the last smaller element
    swap (arr[i + 1], arr[right]);
    
    return i + 1;
}

void quickSort (int arr[], int left, int right) {
    if (left < right) {
        int pi = partition (arr, left, right);

        quickSort (arr, left, pi - 1);
        quickSort (arr, pi + 1, right);
    }
}

int main () {
    int arr[] = {5, 9, 2, 7, 11};
    // int arr[] = {14, 9, 5, 11, 8, 17, 9};
    
    int left = 0, right = sizeof (arr) / sizeof (arr[0]) - 1;
    
    quickSort (arr, left, right);
    
    for (int x : arr) cout << x << " ";
    
    return 0;
}


/*

Quick Sort is a Divide and Conquer sorting algorithm.
It sorts in-place.

Working Principle:
	1. Choose a Pivot element
	2. Rearrange the array so that:
		Elements smaller than pivot → left side
		Elements greater than pivot → right side
	3. Recursively apply the same process to left and right parts
	
	This rearranging step is called Partitioning.


Time Complexity: 
	Best/Average case	:	O(n log n)
	Worst case			:	O(n²)
	
Space Complexity		: 	O(n)   (Uses extra arrays during merging)

*/