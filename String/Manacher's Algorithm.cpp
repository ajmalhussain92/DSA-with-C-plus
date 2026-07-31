#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Manacher {
public:
	// 1. Convert the string (with separators and sentinels)
	string ms;

	Manacher (string &s) {
		ms = "@";
		for (char c : s) 
			ms += "#" + string(1, c);

		ms += "#$";
		
		runManacher();
	}
	
	// 2. Radius array
	int n = ms.size();
	vector<int> p(n, 0);
	
	// 3. The clever observation
	void runManacher () {
		int left = 0, right = 0;

		// Main loop
		for (int i = 1; i < n - 1; i++) {

			int mirror = left + right - i;

			if (i < right)
				p[i] = min (right - i, p[mirror]);

			while (ms[i + 1 + p[i]] == ms[i - 1 - p[i]])
				p[i]++;

			if (i + p[i] > right) {
				left = i - p[i];
				right = i + p[i];
			}
		}
	}

	int getLongest (int center, int odd) {
		int pos = 2 * center + 2 + !odd;
		return p[pos];
	}

	// checks whether substring s[l...r] is a palindrome
	bool check (int left, int right) {
		int len = right - left + 1;
		int longest = getLongest ((left + right) / 2, len % 2);
		return len <= longest;
	}
};


int minChar (string &s) {
	int n = s.size();
	Manacher m(s);

	for (int i = n - 1; i >= 0; --i) {
		if (m.check(0, i))
			return n - (i + 1);
	}

	return n - 1;
}


int main () {
	string s = "abc";
    
    Manacher m (s);
    
    cout << minChar (s);

	return 0;
}

/*

Manacher's Algorithm
	-> Manacher's Algorithm is an advanced string algorithm used to find Longest Palindromic Substring in linear time.
	-> Find the Longest Palindromic Substring (and the palindrome radius at every position) in O(n) time.
	-> It was invented by Glenn K. Manacher in 1975.


Steps: 
	1. Convert the string
	
		The biggest problem is that palindromes have two types: Odd (racecar) and Even (abba)
		Manacher converts everything into odd-length palindromes.

		Example: abba 	becomes 	#a#b#b#a#

		Sometimes implementations also add sentinels: ^#a#b#b#a#$

		Now every palindrome has exactly one center.


	2. Build Radius array
	
		Manacher stores P[i], which means Radius of the palindrome centered at position i

		Example: #a#b#b#a#

			Index : 0 1 2 3 4 5 6 7 8
			Char  : # a # b # b # a #
			P     : 0 1 0 1 4 1 0 1 0


		P[4] = expands four positions each side.
		P[0] = expands 0 positions each side.
		P[1] = expands 1 positions each side.


	3. The clever observation
	
		Mirror:
			mirror = 2 * center - i		OR 		mirror = left + right - i

			mirror is the position symmetric to i about the center of the current longest palindrome


--------------------------------------------------------------
Problems:
	LeetCode 5 — Longest Palindromic Substring
	LeetCode 647 — Count Palindromic Substrings
	LeetCode 214 — Shortest Palindrome

*/