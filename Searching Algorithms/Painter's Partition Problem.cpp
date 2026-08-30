#include <iostream>
#include <vector>
#include <algorithm>  // max_element
#include <numeric>    // accumulate
using namespace std;

bool isPossible (vector<int>& arr, int painters, int maxAllowedTime) {
    int painter = 1;
    int timeTaken = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] + timeTaken <= maxAllowedTime) {
            timeTaken += arr[i];
        }
        else {
            painter++;
            timeTaken = arr[i];
        }
    }
    
    return painter <= painters;
}

int minTimeToPaint (vector<int>& arr, int painters) {
    
    int low = *max_element (arr.begin(), arr.end());
    int high = accumulate (arr.begin(), arr.end(), 0);
    
    int ans = -1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (isPossible (arr, painters, mid)) {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    
    return ans;
}

int main () {
	vector<int> arr = {40, 30, 10, 20};
    int painters = 2;

    cout << minTimeToPaint (arr, painters);

	return 0;
}

/*

Painter's Partition Problem

Goal: Minimize the maximum amount of work assigned to any painter

Idea: Binary Search on Answer + Greedy Check

Each painter paints a contiguous sequence of boards.

Book Allocation          Painter's Partition
------------------------------------------------
books                    boards
pages                    board length/work
students                 painters
pages assigned           work assigned

------------------------------------------------
Time  -> O(n log(sum(arr)))
Space -> O(1)

*/