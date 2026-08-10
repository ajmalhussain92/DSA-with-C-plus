#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void buildLps (string pattern, vector<int>& lps) {
	int m = pattern.size();
	lps[0] = 0;
	int len = 0;

	int i = 1;
	while (i < m) {
		if (pattern[i] == pattern[len]) {
			len++;
			lps[i] = len;
			i++;
		} else {
			if (len != 0)
				len = lps[len - 1];
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
}

string shortestPalindrome (string s) {
	string rev = s;
	reverse (rev.begin(), rev.end());

	string pattern = s + "#" + rev;

	vector<int> lps (pattern.size());
	buildLps (pattern, lps);

	int longest = lps.back();
	string remain = s.substr (longest);

	reverse (remain.begin(), remain.end());

	return remain + s;
}

int main () {
    string s = "aacecaaa";
    
    cout << shortestPalindrome(s);
}

/*

Example 1:
	Input: s = "aacecaaa"
	Output: "aaacecaaa"

Example 2:
	Input: s = "abcd"
	Output: "dcbabcd"



*/