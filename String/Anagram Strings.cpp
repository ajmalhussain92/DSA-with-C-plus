#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isAnagram (string s, string t) {
	int n = s.length();
	int m = t.length();

	if (n != m) return false;

	// 1. sort both s and t
	sort (s.begin(), s.end());
	sort (t.begin(), t.end());

	// 2. compare each character
	for (int i = 0; i < n; i++) 
		if (s[i] != t[i]) 
			return false;


	return true;
}

int main () {
	string s1 = "geeks";
    string s2 = "kseeg";
    
	cout << isAnagram (s1, s2) << endl;

	return 0;
};

/*

Anagram:
    Two strings are called Anagram, if they contain the same characters with the same frequencies.


*/