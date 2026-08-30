#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

bool isPossible (vector<int>& arr, int cows, int minDist) {		// O(n)
    int c = 1;
    int last = arr[0];
    
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] - last >= minDist) {
            c++;
            last = arr[i];
        }
        
        if (c >= cows)
            return true;
    }
    
    return false;
}

int aggressiveCows (vector<int>& arr, int cows) {
    sort (arr.begin(), arr.end());				// O(n log n)
    int ans = 0;
    
    int low = 1;								// Minimum possible distance
    int high = arr.back() - arr.front();		// Maximum possible distance
    
    while (low <= high) {						// O(logRange * n)
        int mid = (low + high) / 2;
        
        if (isPossible (arr, cows, mid)) {
            ans = mid;
            low = mid + 1;						// Find bigger value at right side
        }
        else
            high = mid - 1;
    }
    
    return ans;
}

int main () {
	vector<int> arr = {3, 7, 8, 12};
    int cows = 3;

    cout << aggressiveCows (arr, cows);

	return 0;
}

/*

Aggressive Cows

Goal:	"Maximize the minimum..." or "Minimize the maximum..."

Idea: Binary Search on Answer + Greedy Check

	-> We don't binary-search the array.
	-> Instead, we binary-search the answer — the minimum distance.

-------------------------------------------------------
Example 1:
	stalls = [1, 2, 4, 8, 9]	low = 1, high = 8

answer-search range:
	1  2  3  4  5  6  7  8
	↑                 ↑
   low               high

Example 2:
	stalls = [3, 7, 8, 12]	low = 1, high = 9

answer-search range:
	1   2   3   4   5   6   7   8   9
-------------------------------------------------------
Binary Search on Answer:

Stalls:				[3, 7, 8, 12]

Possible answers:	[1, 2, 3, 4, 5, 6, 7, 8, 9]

mid → a POSSIBLE ANSWER
-------------------------------------------------------
Time  → O(log (range) * n)
Space → O(1)

-------------------------------------------------------
Minimize something:

while (lo <= hi) {
    mid = lo + (hi - lo) / 2;

    if (possible(mid)) {
        ans = mid;
        hi = mid - 1;
    }
    else {
        lo = mid + 1;
    }
}

-------------------------------------------------------
Maximize something:

while (lo <= hi) {
    mid = lo + (hi - lo) / 2;


    if (possible(mid)) {
        ans = mid;
        lo = mid + 1;
    }
    else {
        hi = mid - 1;
    }
}

*/
