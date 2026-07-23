#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> countDistinct (vector<int>& arr, int k) {

	unordered_map<int, int> freq;
	vector<int> res;

	int left = 0;

	for (int right = 0; right < arr.size(); right++) {

		// Expand
		freq[arr[right]]++;

		// When window reaches size k
		if (right - left + 1 == k) {

			res.push_back (freq.size());

			// Slide the window by one position
			freq[arr[left]]--;

			if (freq[arr[left]] == 0)
				freq.erase (arr[left]);

			left++;
		}
	}

	return res;
}

int main () {
	vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
	int k = 4;

	vector<int> res = countDistinct (arr, k);

	for (int ele : res) cout << ele << " ";

	return 0;
}