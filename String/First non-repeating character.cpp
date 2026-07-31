#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

char nonRepeatingChar (string &s) {
    
	unordered_map<char, int> mp;
    
    // Count the frequency of every character.
	for (char c : s)
		mp[c]++;
    
    // Check the frequency of each character
	for (char c : s) {

		if (mp[c] == 1)
			return c;
	}

	return '$';
}

int main () {
	string s = "aabbccc";
	
    cout << nonRepeatingChar (s) << endl;

	return 0;
};

/*

Input: s = "geeksforgeeks"
Output: 'f'
Explanation: 'f' is the first character in the string which does not repeat.

Input: s = "racecar"
Output: 'e'
Explanation: 'e' is the only character in the string which does not repeat.

Input: "aabbccc"
Output: '$'
Explanation: All the characters in the given string are repeating.


*/