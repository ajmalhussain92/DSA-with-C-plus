#include <iostream>
#include <vector>
using namespace std;

int xorAllNums (vector<int>& nums1, vector<int>& nums2) {
	int ans = 0;

	if (nums2.size() % 2 == 1) {
		for (int x : nums1)
			ans ^= x;
	}

	if (nums1.size() % 2 == 1) {
		for (int x : nums2)
			ans ^= x;
	}

	return ans;
}

int main () {
	vector<int> nums1 = {2,1,3};
	vector<int> nums2 = {10,2,5,0};

	cout << xorAllNums (nums1, nums2);

	return 0;
}