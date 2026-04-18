#include <iostream>
#include <cstring>
using namespace std;

// Suitable for computing factorial multiple times or for larger n
// Top-Down DP (Recursion + Memoization)

int dp[10];      // or larger size as needed

int fact (int n) {
    
    // Base cases
    if (n <= 1) 
        return dp[n] = 1;       // store and return
    
	if (dp[n] != -1) 
        return dp[n];

    return dp[n] = n*fact(n-1); // store and return
}

int main () {
    
    memset(dp, -1, sizeof(dp));
    
    int n;
    cout << "Enter num: ";
    cin >> n;
    
    int res = fact(n);
    
    for (int x : dp) {
        cout << x << " ";
    }
    
    cout << "\nFactorial: " << res;
    
    return 0;
}