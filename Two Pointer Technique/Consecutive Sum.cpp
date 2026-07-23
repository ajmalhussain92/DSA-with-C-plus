#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int consecutiveSum (vector<int>& arr, int k, int target) {
	int n = arr.size();

	int left = 0;
	int right = k - 1;

	int sum = 0;
    
    for (int i = 0; i <= right; i++)
        sum += arr[i];
    
    if (sum == target)
		return left;
    
    while (right < n -1) {
        left++;
        right++;
        
        sum = sum - arr[left - 1] + arr[right];
        
        if (sum == target)
            return left;
    }

	return -1;
}

// Same version, but avoids maintaining separate left and right variables explicitly
int consecutiveSum (vector<int>& arr, int k, int target) {
    int n = arr.size();
    
    int sum = 0;
    
    for (int i = 0; i < k; i++)
        sum += arr[i];
    
    if (sum == target)
		return 0;
    
    for (int right = k; right < n; right++) {
        
        sum = sum - arr[right - k] + arr[right];
        
        if (sum == target)
            return right - k + 1;
    }
    
    return -1;
}

// Fixed-size sliding (Standard approach)
int consecutiveSum (vector<int>& arr, int k, int target) {
	int n = arr.size();

	int left = 0;
	int sum = 0;

	for (int right = 0; right < n; right++) {

		sum += arr[right];
		
		if (sum == target)
		    return left;

		if (right - left + 1 == k) {
			sum -= arr[left];
			
			left++;
		}
	}
	
	return left;
}

int main () {
	vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
	int k = 3;
	int target = 15;

	cout << consecutiveSum (arr, k, target);

	return 0;
}

/*

Fixed-size sliding

with maintaining separate left and right variables explicitly

*/