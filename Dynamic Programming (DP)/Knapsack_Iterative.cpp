#include <iostream>
using namespace std;       

struct Item {
  int value;
  int weight;
};

int dp[10][10];    // dp[n][W]     // generic size

// Iterative function
int knapsack (Item items[], int n, int W) { 
    if (n == 0 || W == 0) return 0;
    
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) dp[i][w] = 0;
            
            else if (items[i - 1].weight <= w) 
                dp[i][w] = max ( 
                    items[i - 1].value + dp[i - 1][w - items[i - 1].weight],
                    0 + dp[i - 1][w]);
            
            else 
                dp[i][w] = dp[i - 1][w];
        }
    }
    
    return dp[n][W];
} 

int main () { 
    Item items[] = {
        {110, 1},
        {320, 4},
        {230, 3},
        {450, 5}
    };
    
    int W = 7;                                  	// Knapsack weight
    int n = sizeof (items) / sizeof (items[0]);   	// No. of items

    int maxValue = knapsack (items, n, W);

    cout << "Maximum value in Knapsack = " << maxValue << endl;
    

    return 0;
}
