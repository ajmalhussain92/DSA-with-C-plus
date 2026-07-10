#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraysDivByK (vector<int>& nums, int k) {
	int n = nums.size();

	unordered_map<int, int> mp;
	mp[0] = 1;                      // Empty prefix

	int prefSum = 0;
	int count = 0;

	for (int num : nums) {

		prefSum += num;
		int rem = ((prefSum % k) + k) % k;

		if (mp.find (rem) != mp.end())
			count += mp[rem];

		mp[rem]++;
	}

	return count;
}

int main () {
	vector<int> arr = {4, 5, 0, -2, -3, 1};
	int k = 5;

	cout << subarraysDivByK (arr, k);

	return 0;
}


/*

Hash Map stores:
	Frequency of remainder

Lookup:
	prefSum % k


*/