
// 1. Fixed Size Window ----------------------------------------

int left = 0;

// Variables needed
// int sum = 0;

for (int right = 0; right < n; right++) {

    // 1. Expand the window
    // sum += arr[right];

    // 2. Window reached size k
    if (right - left + 1 == k) {
    	
        // Process the current window

        // 3. Slide the window
        // sum -= arr[left];
        left++;
    }
}


// 2. Variable Size Window --------------------------------------

int left = 0;

// Any data structure or variable needed
// int sum = 0;
// unordered_map<char, int> freq;

for (int right = 0; right < n; right++) {
	
    // 1. Expand the window
    // Include arr[right]
    // sum += arr[right];
    // freq[arr[right]]++;

    // 2. Shrink the window until it becomes valid
    while (/* window is invalid */) {
    	
        // Remove arr[left]
        // sum -= arr[left];
        // freq[arr[left]]--;

        left++;
    }

    // 3. Process the current valid window
    // Update answer
}


/*

Types of Sliding Window

	1. Fixed Size Window
		Window size never changes.

	2. Variable Size Window
		Here the window grows and shrinks.


Sliding Window works whether the array is sorted or unsorted.

Note:- Dynamic/Variable Size Window works for both dynamic and fixed-size problems.

*/