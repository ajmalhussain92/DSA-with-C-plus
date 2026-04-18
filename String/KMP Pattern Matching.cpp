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

int KMPsearch (string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    vector<int> lps(m);
    buildLPS (pattern, lps);

    int i = 0, j = 0;

    while (i < n) {

        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m)
            return i - j;

        else if (i < n && text[i] != pattern[j]) {

            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return -1;
}

int main () {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABC";

    int index = KMPsearch (text, pattern);

    if (index != -1)
        cout << "Pattern found at index: " << index;
    else
        cout << "Pattern not found";

    return 0;
}

/*

Steps:
	1. Build LPS array (Longest Prefix which is also Suffix)
	2. Use LPS to perform pattern matching efficiently

LPS[i] = length of the longest proper prefix of the pattern that is also a suffix for substring [0..i]

------------------------------------------------------

Time Complexity: O(n + m)

where:
	n = text length
	m = pattern length

*/