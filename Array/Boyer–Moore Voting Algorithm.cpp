#include <iostream>
using namespace std;

int majorityElement (int arr[], int n) {
    int candidate = arr[0];		// Assume 1st element as majority
    int count = 1;				

    // Phase 1: Find candidate
    for (int i = 1; i < n; i++) { 
        if (arr[i] == candidate)
            count++;
        else
            count--;

        if (count == 0) {
            candidate = arr[i];
            count = 1;
        }
    }
    
    cout << "Candidate chosen: " << candidate << endl;
    cout << "Phase 1 freq: " << count << endl;

    // Phase 2: Verify candidate
    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate)
            count++;
    }
	
	cout << "Phase 2 freq: " << count << endl;
	
    if (count > n / 2)
        return candidate;
    else
        return -1;
}

int main() {
    int arr[] = {1,1,1,2,2,2,1,1,0};	//2, 2, 1, 2, 3, 2, 2
    int n = sizeof (arr) / sizeof (arr[0]);

    int ans = majorityElement (arr, n);
    
    if (ans != -1)
    	cout << "Candidate is: " << ans << endl;
    else
    	cout << "No majority element found" << endl;
    
    return 0;
}

/*
Standard Moore Voting:

	Phase 1 ? find candidate	
				candidate = element that survived cancellation, NOT guaranteed unless verified
				count = Net balance after cancellations, NOT actual frequency.

	Phase 2 ? verify candidate
				count = Actual frequency. Exact number of times the candidate appears.
*/