#include <iostream>
#include <vector>
using namespace std;

int longestPalindrome (string &s) {
	int n = s.size();
	int count = 0;

	int left;
	int right;

	for (int i = 0; i < n; i++) {

		// even
		left = i;
		right = i + 1;

		while (left >= 0 && right < n && s[left] == s[right]) {
			left--;
			right++;
		}

		count = max (count, right - left - 1);

		// odd
		left = i;
		right = i;

		while (left >= 0 && right < n && s[left] == s[right]) {
			left--;
			right++;
		}

		count = max (count, right - left - 1);
	}

	return count;
}


int main () {
	string s = "babad";

	cout << longestPalindrome (s);

	return 0;
}

/*

Every palindrome has either: 
	one center (odd length) or 
	two centers (even length)


Algorithm:

For every index

	expand(i, i);      // Odd-length palindromes
	expand(i, i + 1);  // Even-length palindromes

If I already have a palindrome, can I make it bigger?

Complexity
	Time : O(n²)
	Space : O(1)

---------------------------------------------------------------
Instead return palindromic substring:

int len = 0;
int start = 0;

len = right - left - 1;

if (len > maxLen) {
	maxLen = len;
	start = left + 1;
}

return s.substr (start, maxLen);

*/