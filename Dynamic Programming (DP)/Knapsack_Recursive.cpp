#include <iostream>
#include <cstring>
using namespace std;       

struct Item { 
  int value;
  int weight;
};

int dp[10][10];    // dp[n][W]     // generic size

// Recursive function
int knapsack (Item items[], int n, int W) { 

    // Base case
    if (n == 0 || W == 0) return 0;

    // Memoization check
    if (dp[n][W] != -1) return dp[n][W];

    // If weight of current item is less than or equal to capacity, take it
    if (items[n - 1].weight <= W) 
        return dp[n][W] = max ( 
            items[n - 1].value + knapsack (items, n - 1, W - items[n - 1].weight),	
            0 + knapsack (items, n - 1, W)							               
    );

    //If weight of current item is more than capacity, check next item
    return dp[n][W] = knapsack (items, n - 1, W);
} 

int main () { 
    Item items[] = { 
        {110, 1},
        {320, 4},
        {230, 3},
        {450, 5} 
    };
    
    int W = 7;                                  // Knapsack weight
    int n = sizeof(items) / sizeof(items[0]);   // No. of items
    

    // Initialize dp table with -1
    memset (dp, -1, sizeof (dp));

    int maxValue = knapsack (items, n, W);

    cout << "Maximum value in Knapsack = " << maxValue << endl;
    

    return 0;
}

/*

Time Complexity: O(n × W)

*/
