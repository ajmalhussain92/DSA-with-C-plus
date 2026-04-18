#include <iostream>
using namespace std;

// Bottom-Up DP (Iteration + Tabulation)
int dp[100];

int fib (int n) {
	
	// Base cases
	if (n == 1 || n == 2) return 1;
	
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	
	// Build table bottom-up
	for (int i = 3; i < n; i++) 
        dp[i] = dp[i - 1] + dp[i - 2];
	
	return dp[n - 1];
};

int main () {
	
	int n;
    cout << "Enter n: ";
    cin >> n;
    
    int res = fib (n);
    
	cout << "Fibonacci Number: " << res;
	
	return 0;
}

/*

Take array size 1 more (n+1) in DP. We don't use 0 index in DP.
Bottom-Up DP is generally better (preferred in interviews & practice)

Golden Rule:
	1. Use Top-Down to understand the problem.
	2. Convert to Bottom-Up for optimization.

*/