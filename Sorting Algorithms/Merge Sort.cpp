void merge (int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort (int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort (arr, left, mid);			// for left portion
        mergeSort (arr, mid + 1, right);	// for right portion

        merge (arr, left, mid, right);		// merge left and right sorted halves
    }
}

/*

Merge Sort is a Divide and Conquer algorithm

Working Principle:

	1. Divide → Split the array into two halves
	2. Conquer → Recursively sort both halves
	3. Merge → Merge the two sorted halves into one sorted array

---------------------------------------------------------------------

Time Complexity: 
	Best/Average/Worst case	:	O(n log n)
	
Space Complexity			: 	O(n)   (Uses extra arrays during merging)

*/