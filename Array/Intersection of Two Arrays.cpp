#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

vector<int> nums;

bool isPresent (vector<int>& nums, int res) {
	for (int i=0; i<nums.size(); i++) {
		if (res == nums[i])
			return true;
	}
	return false;
}

//vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//	vector<int>ans;
//	unordered_map<int,int>mpp;
//	set<int>s;
//	for(int i=0; i<nums1.size(); i++) mpp[nums1[i]]=nums1[i];
//	for(int i=0; i<nums2.size(); i++) if(mpp.find(nums2[i])!=mpp.end()) s.insert(nums2[i]);
//	for(auto it:s) ans.push_back(it);
//	return ans;
//}

vector<int> intersection (vector<int>& nums1, vector<int>& nums2, vector<int>& nums) {
	int n1 = nums1.size();
	int n2 = nums2.size();
	int n = max (n1, n2);


	for (int i=0; i<n1; i++) {
		for (int j=0; j<n2; j++) {
			if (nums1[i] == nums2[j]) {
				if (!isPresent (nums, nums1[i])) {
					nums.push_back(nums1[i]);
				}
			}
		}
	}

	return nums;
}

void show_elements (vector<int>& nums) {
	for (int x : nums) {
		cout << x << " ";
	}
}

int main() {
	vector<int> nums1 = {4,0,9};
	vector<int> nums2 = {9,4,1};

	nums = intersection (nums1, nums2, nums);

	show_elements (nums);

	return 0;
}