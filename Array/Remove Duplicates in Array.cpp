#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Time: O(n), Space: O(1)
vector<int> removeDuplicates (vector<int> &arr) {

    if (arr.empty()) return {};

    int n = arr.size();
    int i = 0;								// pointer

    for (int j = 1; j < n; j++) {

        if (arr[i] != arr[j]) {
            i++;
            arr[i] = arr[j];
        }
    }

    vector<int> res;

    for (int j = 0; j <= i; j++)
        res.push_back (arr[j]);

    return res;
}

// Time: O(n), Space: O(n)
vector<int> removeDuplicates (vector<int>& arr) {

	set<int> s;

	for (int x : arr)
		s.insert(x);

	vector<int> res;

	for (auto it : s)
		res.push_back(it);

	return res;
}

int main () {

	vector<int> arr = {1, 2, 2, 2, 3, 4, 4, 5};

	vector<int> res = removeDuplicates (arr);

	for (int x : res) cout << x << " ";

	return 0;
};