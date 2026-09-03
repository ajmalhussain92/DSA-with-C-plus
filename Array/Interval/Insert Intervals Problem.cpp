#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> insertAndMerge (vector<vector<int>>& intervals, vector<int>& newInterval) {
    sort (intervals.begin(), intervals.end());
    
    int n = intervals.size();
    vector<vector<int>> ans;
    
    int i = 0;
    while (i < n && intervals[i][1] < newInterval[0])
        ans.push_back (intervals[i++]);
    
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min (newInterval[0], intervals[i][0]);
        newInterval[1] = max (newInterval[1], intervals[i][1]);
        i++;
    }
    
    ans.push_back (newInterval);
    
    while (i < n)
        ans.push_back (intervals[i++]);
    
    return ans;
}

int main () {
    vector<vector<int>> intervals = {
        {1, 2},
        {3, 5},
        {6, 7},
        {8, 10},
        {12, 16},
    };
    
    vector<int> newInterval = {4,8};
    
    vector<vector<int>> res = insertAndMerge (intervals, newInterval);
    
    for (auto &row : res) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}