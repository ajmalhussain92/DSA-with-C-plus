#include <iostream>
#include <vector>
#include <algorithm>  // max_element
#include <numeric>    // accumulate
using namespace std;

bool isPossible (vector<int>& arr, int students, long long limit) {
    int st = 1;
    long long pages = 0;

    for (int book : arr) {

        if (pages + book <= limit) {
            pages += book;
        }
        else {
            st++;
            pages = book;
        }

        if (st > students)
            return false;
    }

    return true;
}

int allocateBooks (vector<int>& arr, int students) {

    if (students > arr.size())
        return -1;

    long long low = *max_element (arr.begin(), arr.end());

    // 0LL is important!
    long long high = accumulate (arr.begin(), arr.end(), 0LL);

    long long ans = -1;

    while (low <= high) {

        long long mid = low + (high - low) / 2;

        if (isPossible (arr, students, mid)) {
            ans = mid;
            high = mid - 1;     // Valid: try smaller
        }
        else 
            low = mid + 1;      // Invalid: need larger
    }

    return (int)ans;
}

int main () {
	vector<int> books = {2, 1, 3, 4};
    int students = 2;

    cout << allocateBooks (books, students);

	return 0;
}

/*

Goal:   Allocate Minimum Pages
        Minimize the maximum number of pages assigned to any student.

Example:

books = {10, 20, 30, 40}
---------------------------------------------------------------------
Minimum possible answer
    At least one student must receive the largest single book:
    
    max (books) = 40
    low = 40			(Minimize the maximum pages assigned to any student)
---------------------------------------------------------------------
Maximum possible answer
    If one student gets all books:
    
    10 + 20 + 30 + 40 = 100
    high = 100
---------------------------------------------------------------------
Therefore our answer space (search space) is:

40 ----------------------------- 100
|                                 |
low                              high

---------------------------------------------------------------------
Book Allocation / Painter's Partition - Search Space

low  = max(arr);       // smallest possible answer
high = sum(arr);       // largest possible answer

Example: arr = {1, 4, 2, 3}

	low  = max (arr) = 4;
	high = sum (arr) = 10;

Because "mid" represents the maximum amount of work/pages allowed for one student/painter.
The groups must be contiguous.

---------------------------------------------------------------------
Examples:

Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Since there are more students than total books, it's impossible to allocate a book to each student.

Input: arr[] = [22, 23, 67], k = 1
Output: 112
Explanation: Since there is only 1 student, all books are assigned to that student. So, maximum pages assigned to a student is 22 + 23 + 67 = 112.

-------------------------------------------------------
Time  ? O(n log(sum(arr)))
Space ? O(1)

*/