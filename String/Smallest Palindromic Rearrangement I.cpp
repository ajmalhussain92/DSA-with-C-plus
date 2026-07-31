#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

string smallestPalindrome (string s) {
	unordered_map<char, int> mp;

	for (char c : s)
		mp[c]++;

	string left = "";
	string middle = "";

	for (char c = 'a'; c <= 'z'; c++) {

		left += string(mp[c] / 2, c);

		if (mp[c] % 2 == 1)
			middle = c;
	}

	string right = left;
	reverse (right.begin(), right.end());

	return left + middle + right;
}

int main () {
	string s = "babab";
	
	cout << smallestPalindrome (s);

	return 0;
}


/*

string (count, character)

------------------------------------------------------------
Therefore:

	1. Count the frequency of every character.
	2. Take half of each character's frequency for the left half.
	3. Add characters in ascending alphabetical order.
	4. The middle character is the character with the odd frequency.
	5. Mirror the left half.


*/