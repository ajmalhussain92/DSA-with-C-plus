#include <iostream>
#include <cstring>
using namespace std;

// Top-Down DP (Recursion + Memoization)

int dp[10];			// No of Dimension = No of Parameters Passed (changeable Param)

int fib (int n) {
	
	// Base cases
	if (n == 1 || n == 2) return 1;
	
	if (dp[n] != -1) return dp[n];
	
	return dp[n] = fib (n - 1) + fib (n - 2);
};


int main () {
	
	memset (dp, -1, sizeof (dp));		// Only safe for int, unsafe for double.
	
	int n;
    cout << "Enter n: ";
    cin >> n;
    
    int res = fib (n);
    
	cout << "Fibonacci Number: " << res << endl;
	
	return 0;
}

/*

Take array size 1 more (n+1) in DP. We don't use 0 index in DP.

*/