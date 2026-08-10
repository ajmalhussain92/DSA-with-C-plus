#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*  -------- using find() -----------------*/

// Time: O(n), Space: O(n)
bool areRotations (string s1, string s2) {

	if (s1.length() != s2.length())
		return false;

	string temp = s1 + s1;

	return temp.find(s2) != string::npos;
}

/*  -------- using KMP Search -----------------*/

// Time: O(n), Space: O(n)
void buildLps (string pattern, vector<int>& lps) {
    int m = pattern.size();
    
    int len = 0;
    lps[0] = 0;
    
    int i = 1;
    while ( i < m) {
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

bool KMPsearch (string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    
    vector<int> lps(m);
    buildLps (pattern, lps);
    
    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }
        
        if (j == m)
            return true;
        
        else if (i < n && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else 
                i++;
        }
    }
    
    return false;
}

bool areRotations (string s1, string s2) {
    if (s1.length() != s2.length())
        return false;

    string temp = s1 + s1;

    // Use KMP to search s2 in temp
    return KMPsearch (temp, s2);
}

int main () {
	string s1 = "abcd";
    string s2 = "cdab";

    cout << (areRotations (s1, s2) ? "true" : "false");

	return 0;
}


/*

string::npos returns a special constant that means: "No position found."

------------------------------------------------------------
Good Practice:

bool areRotations(const string& s1, const string& s2)
    Now no copy is made.
    The parameters simply refer to the original strings.
    Both names refer to the same string in memory.
    Passing a reference is essentially passing an address (or pointer under the hood), which is O(1).

------------------------------------------------------------
bool areRotations(string s1, string s2)
    When the function is called, C++ copies both strings.
    Results:
        string s1 = "abcdefghijklmnopqrstuvwxyz";
        string s2 = "defghijklmnopqrstuvwxyzabc";

    Memory looks like this:
        main()

            s1 ---> "abcdefghijklmnopqrstuvwxyz"
            s2 ---> "defghijklmnopqrstuvwxyzabc"

           ? Copy

        areRotations()

            s1 ---> "abcdefghijklmnopqrstuvwxyz"
            s2 ---> "defghijklmnopqrstuvwxyzabc"
            
        Two completely new strings are created which takes O(n) time.

*/