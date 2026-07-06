#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

unordered_map<int, int> mp;

// Time O(n), Space O(n)
vector<int> twoSum (vector<int>& nums, int target) {
	unordered_map<int, int> mp;

	for (int i = 0; i < nums.size(); i++) {
	    int need = target - nums[i];
	    
	    if (mp.find (need) != mp.end())
	        return {mp[need], i};
	   
	   mp[nums[i]] = i;
	}

	return {};
}

int main() {
	vector<int> arr = {2,7,11,15};
	int target = 22;

	vector<int> result = twoSum (arr, target);
	
	for (int x : result) cout << x << " ";

	return 0;
}