/* Building string every time  */

int findSubstring (string str, string substring) {
    for (int i = 0; i < str.length(); i++) {
        string s = "";
        for (int j = i; j < str.length(); j++) {
            s += str[j];
            if (s == substring)
                return i;
        }
    }
    return -1;
}

// Time Complexity: O(n³) worst case


// ---------------------------------------------

/* Instead of building string every time  */

int findSubstring(string str, string sub) {
    int n = str.length(), m = sub.length();

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && str[i + j] == sub[j]) {
            j++;
        }
        if (j == m) return i;
    }
    return -1;
}

// Time Complexity: O(n × m)
// Space: O(1)

// ---------------------------------------------

/* Best (STL)  */

int index = str.find (substring);

// Already optimized internally

// find () return the string::npos if not found.

// string::npos is a very large number (like 18446744073709551615 on 64-bit)


// ---------------------------------------------

/* Advanced (KMP Algorithm)  */

// Time Complexity: O(n × m)






