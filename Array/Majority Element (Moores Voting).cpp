#include <iostream>
#include <vector>
using namespace std;

// Moore's Voting Algorithm: majority element (more than n/2 times), regardless sorted or unsorted array
// Time Complexity: O(n)
// Space Complexity: O(1)

int majorityElement (vector<int>& nums) {
	int n = nums.size ();
	int maj = nums[0];
	int freq = 1;
	
	for (int i = 1; i < n; i++) {
		if (nums[i] == maj)
			freq++;
		else 
			freq--;
		
		if (freq == 0) {
			maj = nums[i];
			freq = 1;
		}
	}
	
	freq = 0;
	
	for (int i = 0; i < n; i++) {
		if (maj == nums[i])
			freq++;
	} 
	
	if (freq > n / 2)
		return maj;
	else 
		return -1;
}

int main () {
	vector<int> nums = {1,1,1,2,2,2,1,1,0};

	int ans = majorityElement (nums);
	
	if (ans != -1)
		cout << "Majority element is: " << ans << endl;
	else 
		cout << "No majority element found" << endl;
	

	return 0;
}

/*

Principle:
	1. Pick a candidate
	2. Increase count if same
	3. Decrease count if different
	4. If count becomes 0 ? change candidate

*/