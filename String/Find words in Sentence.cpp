#include <iostream>
#include <sstream>
#include <vector>
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

int KMPSearch (string text, string pattern) {
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
            return i - j;
        
        else if (i < n && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else {
                i++;
            }
        }
    }
    
    return -1;
}

int main () {
    string sentence = "In a village nestled between the mountains and the sea, there was a small, peaceful village where everyone knew each other, and the villagers often gathered at the village square to share stories, celebrate festivals, and enjoy the simple pleasures of life.";
    
    string key;
    cout << "Enter the word to find: ";
    getline (cin, key);
    
    cout << KMPSearch (sentence, key);
	return 0;
}