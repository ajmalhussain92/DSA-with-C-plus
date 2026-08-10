#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int countIndexPairs (vector<int>& nums, int k) {
    unordered_map<int, int> freq;

    for (int x : nums)
        freq[x]++;

    int count = 0;

    for (auto &[x, f] : freq) {
        if (freq.count (x + k))
            count += f * freq[x + k];
    }

    return count;
}

int main () {
	vector<int> nums = {3,1,4,1,3,3,5};
	int k = 2;
	
	cout << countIndexPairs (nums, k);

	return 0;
}

/*

freq = {
    1 : 2,
    3 : 3,
    4 : 1,
    5 : 1
}

1 appears 2 times
3 appears 3 times
5 appears 1 time

For value 1, its partner is 3.

Number of index pairs:

    freq(1) × freq(3) = 2 × 3 = 6

For value 3, its partner is 5.

    freq(3) × freq(5) = 3 × 1 = 3

Total: 6 + 3 = 9

--------------------------------------------------------------------
for (auto &[x, f] : freq)

Each element of an unordered_map is actually a pair: pair<const int, int>
It looks like:
(key, value)
(1,2)
(3,3)
(5,1)

Without structured binding:
for (auto &p : freq) {
    cout << p.first << " ";
    cout << p.second << endl;
}

With structured binding (C++17):
for (auto &[x, f] : freq)
This means
    x = p.first, f = p.second So, x → number (key), f → frequency (value)
--------------------------------------------------------------------
auto &[x, f] and auto [x, f]
Both work here, but & avoids unnecessary copying.

--------------------------------------------------------------------
if (freq.count(x + k))

count() returns an integer.

For an unordered_map: 
freq.count(key)

returns
    1  -> key exists
    0  -> key doesn't exist

*/