#include <iostream>
#include <vector>
using namespace std;

int maxSumWithK (vector<int>& arr, int k) {
    int n = arr.size();
    
    // Kadane's Algorithm		(only Best End, curr = arr[0])
    vector<int> bestEnd(n);
    bestEnd[0] = arr[0];
    
    for (int i = 1; i < n; i++)
        bestEnd[i] = max (arr[i], bestEnd[i - 1] + arr[i]);
    
    // Sliding Window
    int windowSum = 0;
    for (int i = 0; i < k; i++)
        windowSum += arr[i];
    
    int ans = windowSum;
    
    for (int right = k; right < n; right++) {

		windowSum += arr[right];
		windowSum -= arr[right - k];

		// Case 1: Take only this window
		ans = max (ans, windowSum);

		// Case 2: Attach a positive subarray before it
		ans = max (ans, windowSum + bestEnd[right - k]);
	}
    
    return ans;
}

int main () {
	vector<int> arr = {-4, -2, 1, -3};
    int k = 2;
    
	cout << maxSumWithK (arr, k);

	return 0;
};

/*

Kadane's Algorithm + Sliding Window.

The reason is that the subarray length is at least k, not exactly k

Algorithm
    Build bestEnd[] using Kadane.
    Compute first window sum of size k.
    Initialize answer.
    Slide the window.
    At each position
-----------------------------------------------------
Examples:

Input: arr[] = [-4, -2, 1, -3], k = 2
Output: -1
Explanation: The sub-array of length at least 2 that produces greatest sum is [-2, 1]

Input: arr[] = [1, 1, 1, 1, 1, 1], k = 2
Output: 6
Explanation: The sub-array of length at least 2 that produces greatest sum is [1, 1, 1, 1, 1, 1]

Input: arr[] = [1, -2, 2, -3], k = 3
Output: 1
Explanation: The sub-array of length at least 3 that produces greatest sum is [1, -2, 2]

-----------------------------------------------------
The problem asks for:
	Subarrays of length = k

*/