#include <iostream>
using namespace std;

bool repeatedSubstringPattern (string s) {
	string temp = s + s;
	
	// remove the first and last character
	temp = temp.substr(1, temp.size() - 2);
	
	return temp.find(s) != string::npos;
}

int main () {
	string s = "abab";
	
	cout << (repeatedSubstringPattern (s) ? "true" : "false");

	return 0;
}

/*


Complexity:
    s + s ? O(n)
    substr() ? O(n)
    find() ? implementation-dependent but typically efficient in practice.

-------------------------------------------------------------
Example 1:
	Input: s = "abab"
	Output: true
	Explanation: It is the substring "ab" twice.

Example 2:
	Input: s = "aba"
	Output: false

Example 3:
	Input: s = "abcabcabcabc"
	Output: true
	Explanation: It is the substring "abc" four times or the substring "abcabc" twice.


*/