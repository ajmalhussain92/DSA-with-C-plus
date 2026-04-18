
void selectionSort (int arr[], int n) { 
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        
        for (int j = i + 1; j < n; j++) {
            if (arr[min] > arr[j]) {
                min = j;    // min update
            }
        }
        
        if (min != i)
            swap (arr[i], arr[min]);    // swap
    }
} 

/*

Selection Sort is a straightforward comparison-based sorting algorithm.

Working Principle:
	1. Start with the entire list	:	Consider the first element as the minimum (or maximum)
	2. Find the minimum element		: 	Traverse the unsorted part of the list to find the smallest element
	3. Swap							: 	Swap this smallest element with the first element of the unsorted part
	4. Move to the next position	:	Now, consider the next position as part of the sorted section
	5. Repeat						: 	Continue this process for each position in the list until the entire list is sorted

Time Complexity: 
	Best/Average/Worst case: O(n²)
	
It performs well for small datasets.

Principle:
	

*/