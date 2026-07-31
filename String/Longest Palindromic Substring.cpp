#include <iostream>
#include <vector>
using namespace std;

string longestPalindrome (string s) {
	int n = s.size();
	int maxLen = 0;
	int start = 0;
	int len = 0;

	int left;
	int right;
	
	// Expand Around Center
	for (int i = 0; i < n; i++) {

		// odd
		left = i;
		right = i;

		while (left >= 0 && right < n && s[left] == s[right]) {
			left--;
			right++;
		}

		len = right - left - 1;

		if (len > maxLen) {
			maxLen = len;
			start = left + 1;
		}

		// even
		left = i;
		right = i + 1;

		while (left >= 0 && right < n && s[left] == s[right]) {
			left--;
			right++;
		}

		len = right - left - 1;

		if (len > maxLen) {
			maxLen = len;
			start = left + 1;
		}
	}

	return s.substr(start, maxLen);
}

int main () {
	string s = "babad";
	
	cout << longestPalindrome (s);
	
	return 0;
}

/*

Every palindrome has a center.

    Odd-length palindrome  = one center character
    Even-length palindrome = two center characters

The algorithm simply tries every possible center and expands outward as long as the characters match.

---------------------------------------------------------------
Why check both (left right)?

    For every index i, there are two possible centers:

---------------------------------------------------------------
Input: s = "racecar"
Output: "racecar"

Input: s = "babad"
Output: "bab"

Input: s = "cbbd"
Output: "bb"

*/

