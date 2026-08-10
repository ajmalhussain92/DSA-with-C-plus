#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// [Expected Approach] Using Hash Map and Prefix Sum - O(n) Time, O(n) Space
int countSubarrays (vector<int>& arr, int k) {
	int n = arr.size();

	unordered_map<int, int> mp;

	int freq = 0;
	int prefSum = 0;

	for (int i = 0; i < arr.size(); i++) {

		prefSum += arr[i];

		if (prefSum == k)
			freq++;

		if (mp.find(prefSum - k) != mp.end())
			freq += mp[prefSum - k];

		mp[prefSum]++;
	}

	return freq;
}

int main () {
	vector<int> arr = {-5, 8, -14, 2, 4, 12};
	int k = -5;

	cout << countSubarrays (arr, k);
}