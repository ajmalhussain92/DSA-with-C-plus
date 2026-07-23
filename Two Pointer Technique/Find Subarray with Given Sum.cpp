#include <iostream>
#include <vector>
using namespace std;

vector<int> subarraySum(vector<int>& arr, int target) {

    int left = 0;
    int sum = 0;

    for (int right = 0; right < arr.size(); right++) {

        // 1. Expand the window
        sum += arr[right];

        // 2. Shrink the window until it becomes valid
        while (sum > target && left <= right) {
            sum -= arr[left];
            left++;
        }

        // 3. Process the current window
        if (sum == target) {
            return {left + 1, right + 1};   // 1-based indexing
        }
    }

    return {-1};
}

int main() {
    vector<int> arr = {15, 2, 4, 8, 9, 5, 10, 23};
    int target = 23;
    
    vector<int> res = subarraySum (arr, target);
    
    for (int ele : res) cout << ele << " ";
    
    return 0;
}

/*

Problem:
	Return the first subarray whose sum is equal to target.
	Return the first occurrence.
	In case of multiple subarrays, find the subarray indexes which come first on moving from left to right.
	
	
	Solution: Sliding Window fits pefectly.
	
	The sliding window moves only forward:
		right only increases.
		left only increases.


*/