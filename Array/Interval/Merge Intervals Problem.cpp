#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

vector<vector<int>> merge (vector<vector<int>>& intervals) {
    if (intervals.empty()) 
        return {};
    
    // 1. Sort by START
    sort (intervals.begin(), intervals.end());

	vector<vector<int>> ans;
	
	for (auto &interval : intervals) {
	
	    if (ans.empty() || interval[0] > ans.back()[1]) 
	        // No overlap
	        ans.push_back (interval);

	    else 
	        // Overlap
	        ans.back()[1] = max (ans.back()[1], interval[1]);
	}
    
    return ans;
}

int main () {
	vector<vector<int>> intervals {
		{1, 3},
		{2, 6},
		{8, 10},
		{15, 18},
	};
	
	vector<vector<int>> res = merge (intervals);
	
	// See result:
	for (auto& row : res) {
	    for (auto& val : row) {
	        cout << val << " ";
	    }
	    cout << endl;
	}

	return 0;
}



/*

Merge Intervals Problem:
	1. Sort : Sort by START time
	2. Pick first activity
	3. Overlapping? Merge : Push in the result


Goal:
	-> Combine overlapping intervals

Why sort by START time?
	-> We need overlapping intervals to come together.
	-> Overlapping intervals become adjacent.
	-> All possible overlapping intervals appear continuously.
	-> So we can merge easily.

--------------------------------------------

Need earliest finishing? 	sort by END
Need overlap grouping? 		sort by START

-------------------------------------------------
Overlap logic:

start1 <= end2
AND
start2 <= end1

*/