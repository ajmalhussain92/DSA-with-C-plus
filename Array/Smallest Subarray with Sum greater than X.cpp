#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int smallestSubWithSum(int x, vector<int>& arr) {

    int n = arr.size();
    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {

        int sum = 0;

        for (int j = i; j < n; j++) {

            sum += arr[j];

            if (sum > x) {
                ans = min(ans, j - i + 1);
                break;              // No need to extend further from this i
            }
        }
    }

    return (ans == INT_MAX) ? 0 : ans;
}

int main () {

	vector<int> arr = {1,4,45,6,0,19};
	
	int x = 51;
    
    cout << smallestSubWithSum (arr, x);
    
	return 0;
};