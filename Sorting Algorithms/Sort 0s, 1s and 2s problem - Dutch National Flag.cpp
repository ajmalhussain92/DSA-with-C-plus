#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void sortColors (vector<int>& arr) {
    int lo = 0;
    int mid = 0;
    int hi = arr.size() - 1;

    while (mid <= hi) {
        if (arr[mid] == 0) 
            swap (arr[mid++], arr[lo++]);
        
        else if (arr[mid] ==  1)
            mid++;
        
        else
            swap (arr[mid], arr[hi--]);
    }
}

int main () {
	vector<int> arr = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
	
	sortColors (arr);

    for (int x : arr) cout << x << " ";

	return 0;
}

/*

Dutch National Flag (DNF)

	-> It was introduced by Edsger W. Dijkstra.

Goal: Sort an array containing only 0, 1, and 2 in O(n) time, O(1) space, One pass

-----------------------------------------------------------------------
DNF uses three pointers:
	lo = 0, mid = 0, hi = n - 1; 		(initially)

The mid pointer examines the unknown element.

If arr[mid] == 0 -> swap (arr[mid], arr[low]); mid++; low++;
If arr[mid] == 1 -> mid++
If arr[mid] == 2 -> swap (arr[mid], arr[high]); high--;

-----------------------------------------------------------------------

Time: O(n)
Space: O(1)

*/