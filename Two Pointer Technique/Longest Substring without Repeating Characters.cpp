#include <iostream>
#include <vector>
using namespace std;

int longestUniqueSubstr (string &s) {

    int count = 0;
    
    vector<int> lastIndex (26, -1);

    int left = 0;

    for (int right = 0; right < s.size(); right++) {

        left = max (left, lastIndex[s[right] - 'a'] + 1);

        count = max (count, right - left + 1);

        lastIndex[s[right] - 'a'] = right;
    }
    
    return count;
}

int main () {
    string s = "abcbadbd";
    
    cout << longestUniqueSubstr (s);
    
    return 0;
}