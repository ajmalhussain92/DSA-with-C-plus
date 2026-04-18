#include <iostream>
#include <cstring>
using namespace std;

// Bottom-Up DP (Iteration + Tabulation)

int dp[10];

int fact (int n) {
    
    // Base Case
    if (n <= 1) 
        return 1;       
    
    dp[0] = 1;
	dp[1] = 1;
    
    // Build table bottom-up
    for (int i=2; i<=n; i++){
    	dp[i] = dp[i-1] * i;
	}
	
	return dp[n];
}

int main () {
    
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