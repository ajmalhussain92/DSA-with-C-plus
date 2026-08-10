#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

bool check (vector<int>& arr, int k, int minDist) {

    int cows = 1;
    int last = arr[0];

    for (int i = 1; i < arr.size(); i++) {

        if (arr[i] - last >= minDist) {
            cows++;
            last = arr[i];
        }

        if (cows >= k)
            return true;
    }

    return false;
}

int aggressiveCows(vector<int>& arr, int k) {

    sort(arr.begin(), arr.end());

    int low = 1;
    int high = arr.back() - arr.front();

    int ans = 0;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (check(arr, k, mid)) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}

int main () {
	vector<int> arr = {1, 2, 4, 8, 9};
    int k = 3;

    cout << aggressiveCows (arr, k);

	return 0;
}

/*

"Maximize the minimum..." or "Minimize the maximum..."
Often think about Binary Search on Answer.


*/
