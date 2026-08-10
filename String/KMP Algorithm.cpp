#include <iostream>
#include <vector>
using namespace std;

void buildLPS (string pattern, vector<int>& lps) {
    int m = pattern.length();
    int len = 0;
    lps[0] = 0;

    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> KMPsearch (string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    vector<int> lps(m);
    buildLPS (pattern, lps);
    
    vector<int> ans;
    int i = 0, j = 0;

    while (i < n) {

        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            ans.push_back (i - j);			// or return i - j; for first occurrence
            j = lps[j - 1];
        }

        else if (i < n && text[i] != pattern[j]) {

            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return ans;
}

int main () {
    string text = "aabaacaadaabaaba";
    string pattern = "aaba";

    vector<int> res = KMPsearch (text, pattern);

    for (int x : res) cout << x << " ";

    return 0;
}

/*

KMP = Knuth–Morris–Pratt
	It is an efficient algorithm for pattern matching (finding all occurrences of a pattern in a text).
	A naive algorithm restarts matching from the next character after a mismatch, causing many repeated comparisons.
	KMP avoids those repeated comparisons by using information from the pattern itself.

Idea:
	When a mismatch occurs, don't move the text pointer backward. Instead, use the LPS array to decide where to continue in the pattern.

------------------------------------------------------
Steps:
	1. Build LPS array 	(LPS = Longest Proper Prefix which is also a Suffix)
	2. Search 			(This version returns all starting indices of the pattern)

LPS[i] = length of the longest proper prefix of the pattern that is also a suffix for substring [0..i]

------------------------------------------------------
Time: O(n + m)
Space: O(m)

where:
	n = text length
	m = pattern length

------------------------------------------------------
Real-Life Applications
	Text Editors (Find feature)
	Plagiarism Detection
	Bioinformatics (DNA sequence matching)
	Spam Detection Systems
	Search Engines

------------------------------------------------------
Input: txt = "abcab",  pat = "ab"
Output: [0, 3]
Explanation: The string "ab" occurs twice in txt, first occurrence starts from index 0 and second from index 3.

Input: txt=  "aabaacaadaabaaba", pat =  "aaba"
Output: [0, 9, 12]
------------------------------------------------------
LPS = Longest Prefix Suffix

Prefix: A prefix must start from index 0
Suffix: A suffix must end at the last index

Example 1:
Pattern: a b a b a b

Prefix   Suffix
------   ------
a        b     
ab       ab    
aba      bab   
abab     abab   
ababa    babab  


Example 2:
Pattern: a j m a l

Prefix   Suffix
------   ------
a        l     
aj       al    
ajm      mal  
ajma     jmal   


*/