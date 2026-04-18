
void bubbleSort (int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap (arr[j], arr[j + 1]);
            }
        }
    }
}

/*

Bubble Sort is a simple comparison-based sorting algorithm.

Working Principle:
	1. Compare Adjacent Elements:	Start from the beginning of the list and compare the first two elements
	2. Swap if Necessary		:	If the first element is greater than the second
	3. Move to Next Pair		:	Move one position forward and compare the next pair of adjacent elements
	4. Repeat for Entire List	:	Continue this process until you reach the end of the list. At each pass, largest element reaches o its correct position at the end
	5. Stop When Sorted			:	The algorithm stops when a complete pass is made without any swaps
	

Time Complexity:
	Worst/Average			: 	O(n²)
	Best (already sorted)	: 	O(n)
	
Very easy to understand but slow for large datasets.

*/