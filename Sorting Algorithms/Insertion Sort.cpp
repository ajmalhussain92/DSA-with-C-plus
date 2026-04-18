
void insertionSort (int arr[], int n) { 
    for (int i = 1; i < n; i++) { 
        int key = arr[i];     // element to insert
        int j = i - 1;

        // shift elements greater than key
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j];
            j--;
        } 
		
        arr[j + 1] = key;     // place key in correct position
    } 
} 

/*

Insertion Sort is a simple comparison-based sorting algorithm that builds the sorted list one element at a time
Insertion Sort works exactly like sorting playing cards in your hand.

Working Principle:
	1. Start with the second element	: 	Assume the first element is already sorted
	2. Select the current element		: 	Take the next element in the unsorted portion
	3. Compare and shift				: 	Compare this element with the elements in the sorted portion (to its left)
	4. Insert							: 	Place the current element into its correct position where it is greater than the element before it and less than the element after it
	5. Repeat							: 	Repeat this process for all remaining unsorted elements until the entire list is sorted.


Time Complexity: 
	Average/Worst case	:	O(n²)
	Best case			: 	O(n)
	
Space Complexity: O(1)   (In-place)

--------------------------------------------------------------------------

Principle:
	i) You take one element at a time
	ii) Insert it into its correct position in the already sorted part
	
	It maintains:
		Left side → Sorted
		Right side → Unsorted

	At each step, one element from the unsorted part is picked and inserted into the correct position in the sorted part.

*/