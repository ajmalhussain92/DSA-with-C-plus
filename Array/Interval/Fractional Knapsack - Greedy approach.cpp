#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
  int value;
  int weight;
};

// Sort by value/kg in decreasing order
bool sortByValue (Item i1, Item i2) {
    double price1 = (double)i1.value / i1.weight;
    double price2 = (double)i2.value / i2.weight;
    return price1 > price2;
}

int main () {
    Item items[] = { {21, 7}, {24, 4}, {12, 6}, {40, 5}, {30, 6} };
    
    int n = sizeof (items) / sizeof (items[0]);
    
    // 1. Sort items based on the 'value/weight' in decreasing order
    sort (items, items + n, sortByValue);
    
    int knapsack = 20;
    double profit = 0;
    
    for (int i = 0; i < n; i++) {
        // 2. Take Full item if possible
        if (items[i].weight <= knapsack) {
            profit += items[i].value;
            knapsack -= items[i].weight;
        } 
        // 2. Fraction of item if not possible
        else {
            profit += ((double)items[i].value / items[i].weight) * knapsack;
            knapsack = 0;
            break;
        }
    }
    
    cout << "Max profit in knapsack = " << profit << endl;				// should be max
    cout << "knapsack capacity left = " << knapsack;					// should be zero

	return 0;
}

/*

Fractional Knapsack: 
	? Partial item allowed
	? You can take a fraction of an item.
	? Greedy works
	? Time Complexity: O(n log n)

1. Sort : value/weight  (profit per unit weight)
2. Taking:
    Full item if possible
    Fraction of item if not possible



*/
