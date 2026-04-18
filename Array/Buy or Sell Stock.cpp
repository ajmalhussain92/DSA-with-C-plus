#include <iostream>
#include <climits>
using namespace std;

/* A man looking at past data and saying “Kaash maine is din buy kiya hota… aur is din sell kiya hota…” */

int main () {
    // int prices[] = {10,12,15,6,9,2};
    // int prices[] = {5,9,3,11,7};
    int prices[] = {11,9,15,7,12};
    
    int n = sizeof(prices) / sizeof(prices[0]);
    
    int minPrice = INT_MAX;
    int maxProfit = 0;
    
    for (int i = 0; i < n - 1; i++) {
        if (prices[i] < minPrice)
            minPrice = prices[i];
        else
            maxProfit = max (maxProfit, prices[i] - minPrice);
    }
    
    cout << "maxProfit: " << maxProfit;
    
    return 0;
}

/*

We don’t calculate profit on the same day.

What we do on the next day?

    If price goes higher than the buying price, we calculate maxProfit.
    If price goes down than the buying price, we update the minPrice.


If price > minPrice -> calculate maxProfit
If price < minPrice -> update minPrice

*/