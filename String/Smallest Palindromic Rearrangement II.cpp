#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

long long comb (long long n, long long m, long long k) {
	long long res = 1;
	m = min(m, n - m);

	for (long long i = 1; i <= m; i++) {
		res = res * (n - i + 1) / i;
		if (res > k) {
			return k + 1;
		}
	}
	return res;
}

string smallestPalindrome (string s, int k) {
	int halfLength = s.length() / 2;
	vector<int> bucket(26, 0);

	for (int i = 0; i < halfLength; i++) {
		bucket[s[i] - 'a'] += 1;
	}

	auto permutations = [&](int rem) {
		long long ways = 1;
		for (int i = 0; i < 26; i++) {
			if (bucket[i] == 0) {
				continue;
			}

			ways *= comb (rem, bucket[i], k);
			if (ways > k) {
				break;
			}
			rem -= bucket[i];
		}
		return ways;
	};

	string left = "";
	long long startIndex = 1;

	for (int pos = 0; pos < halfLength; pos++) {

		for (int c = 0; c < 26; c++) {

			if (bucket[c] == 0)
				continue;

			bucket[c]--;

			long long ways = permutations (halfLength - pos - 1);

			if (startIndex + ways > k) {
				left += char(c + 'a');
				break;
			}

			bucket[c]++;
			startIndex += ways;
		}
	}

	if (left.length() < halfLength) {
		return "";
	}

	string mid = s.length() % 2 != 0 ? string (1, s[halfLength]) : "";
	string right = left;
	reverse (right.begin(), right.end());

	return left + mid + right;
}


int main () {
	string s = "madam";
	int k = 1;

	cout << smallestPalindrome (s, k);

	return 0;
}

/*

So the algorithm repeatedly does:

	Try placing 'a'.
	Compute how many distinct permutations remain.

	If that count is less than k, skip all of them:

	k -= count;
	Otherwise, keep 'a' and move to the next position.

	Then repeat for 'b', 'c', etc.


*/