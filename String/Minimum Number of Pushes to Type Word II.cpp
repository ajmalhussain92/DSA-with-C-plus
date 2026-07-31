#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int minimumPushes (string word) {
	int n = word.length();

	unordered_map<char, int> mp;

	for (char c : word)
		mp[c]++;

	vector<int> freq;
	for (auto& it : mp)
		freq.push_back(it.second);

	sort (freq.begin(), freq.end(), greater<int>());

	int ans = 0;

	for (int i = 0; i < freq.size(); i++) {
		ans += freq[i] * (i / 8 + 1);
	}

	return ans;
}


int main () {
	string s = "xyzxyzxyzxyz";

	cout << minimumPushes (s);

	return 0;
}

/*

3016. Minimum Number of Pushes to Type Word II

Algorithm
	1. Count frequencies of 26 letters.
	2. Sort frequencies in descending order.
	3. Traverse the sorted frequencies.
	4. The first 8 frequencies cost x 1.
	5. The next 8 frequencies cost x 2.
	6. The next 8 frequencies cost x 3. and so on ...

---------------------------------------------------------------
Sort in Ascending order:
	sort (freq.begin(), freq.end());

Sort in Descending order:

	Method 1:

	sort (freq.begin(), freq.end(), greater<int>());

	Method 2:

	sort (freq.begin(), freq.end());
	reverse (freq.begin(), freq.end());


*/