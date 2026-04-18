#include <iostream>
using namespace std;

/* Naive Approach and Brute-Force Approach (mean almost the same thing) */

int matchPattern (string& text, string& pattern) {
    int n = text.length();
    int m = pattern.length();
    
    for (int i = 0; i < n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        
        if (j == m) return i;           // pattern matched
    }
    
    return -1;
}

int main () {
    string text = "ABCABBCDACBD";
    string pattern = "BCDA";
    
    int res = matchPattern (text, pattern);
    
    if (res != -1) cout << "String match position: " << res << endl;
        else "No match";

    return 0;
}

/*

Time complexity: O(n x m)
	
	where,
	n = length of text
	m = length of pattern

-------------------------------------------
1. Naive Algorithm
	A Naive Algorithm is the most straightforward and simple way to solve a problem without optimizations.

2. Brute-Force Algorithm
	A Brute-Force Algorithm tries all possible possibilities until the correct one is found.

*/