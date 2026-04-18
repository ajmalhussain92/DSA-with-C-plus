#include <iostream>
#include <string>
using namespace std;

#define d 256   // number of characters in input alphabet

void rabinKarp (string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    
    int p = 0;   // hash value for pattern
    int t = 0;   // hash value for text
    int h = 1;

    int q = 101; // a prime number (mod value)

    // h = pow (d, m-1) % q
    for (int i = 0; i < m - 1; i++)     
        h = (h * d) % q;            				// h remains constant throughout the program

    // calculate initial hash values
    for (int i = 0; i < m; i++) {
        p = (p * d + pattern[i]) % q;
        t = (t * d + text[i]) % q;
    }

    // slide pattern over text
    for (int i = 0; i <= n - m; i++) {

        // check hash match
        if (p == t) {

            bool match = true;

            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {	// verify character by character
                    match = false;
                    break;
                }
            }

            if (match)
                cout << "Pattern found at index " << i << endl;
        }

        // compute hash for next window
        if (i < n - m) {
            // update hash using rolling hash formula
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            if (t < 0)
                t = t + q;
        }
    }
}

int main () {

    string text = "ABCCDDAEFG";
    string pattern = "CDD";

    rabinKarp (text, pattern);

    return 0;
}

/*

For ASCII characters (0-255), d is 256.
Hash match ? Guaranteed string match		(due to Hash Collision)

Steps:
	1. Compute hash (pattern)
	2. Compute hash of first window in text
	3. Compare hash: 
		i) Match: 
			Verify characters
			
		ii) No-match: 
			Slide window one character at a time
			Update hash using rolling hash

---------------------------------------------------------

Time Complexity: O(n + m)

---------------------------------------------------------

Rolling Hash?
	Instead of recomputing hash again and again, The hash is updated using rolling hash formula.

Why Hash Collision?
	A hash function compresses data into a smaller number.
	So different strings can produce the same hash value. This is called: Collision.

h represents the weight of the first character in the hash polynomial.

*/