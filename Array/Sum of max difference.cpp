#include <iostream>
#include <algorithm>
using namespace std;

int maximumDifference (int* arr, int n) {
    // 1. Sort 
    sort (arr, arr + n);
    
    int maxDiffer = 0;
    int i = 0, j = n - 1;
    
    // 2. Subtract
    while (i <= j) 
        maxDiffer += abs (arr[i++] - arr[j--]);
    
    return maxDiffer;
}

int main () {
    int arr[] = {5, 3, 10, 9, 2, 6, 7, 4};
    
    int n = sizeof (arr) / sizeof (arr[0]);
    
    int res = maximumDifference (arr, n);

    cout << "Sum of max difference = " << res << endl;
    
    return 0;
}

/*

Maximum sum of difference in Pair elements using Greedy approach:
	1. Sort : Ascending or descending
	2. Subtract smallest with largest value and add the result

*/