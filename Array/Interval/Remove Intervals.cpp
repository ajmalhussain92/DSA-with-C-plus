#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int removeInterval (vector<vector<int>>& intervals) {
	sort (intervals.begin(), intervals.end());

	int removed = 0;
	int prevEnd = intervals[0][1];

	for (int i = 1; i < intervals.size(); i++) {

		if (intervals[i][0] < prevEnd) {
			// Overlap

			removed++;

			// Keep the interval that ends earlier
			prevEnd = min (prevEnd, intervals[i][1]);
		}
		else 
			// No overlap
			prevEnd = intervals[i][1];
	}
	
	return removed;
}

int main () {
	vector<vector<int>> intervals {
		{1, 3},
		{2, 6},
		{8, 10},
		{15, 18},
	};

	cout << removeInterval (intervals);

	return 0;
}

/*

Find Non-Overlapping Intervals

Goal: Remove minimum number of intervals need make the rest of the intervals non-overlapping.


*/