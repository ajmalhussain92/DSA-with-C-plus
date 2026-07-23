#include <iostream>
#include <vector>
using namespace std;

int trapWater (vector<int>& arr) {

	int left = 1;
    int right = arr.size() - 2;
    
    int lMax = arr[left - 1];
    int rMax = arr[right + 1];
	
	int trap = 0;
	
	while (left <= right) {
	    
	    if (rMax <= lMax) {
	        trap += max (0, rMax - arr[right]);
	        
	        rMax = max (rMax, arr[right]);
	        
	        right--;
	    }
	    else {
	        trap += max (0, lMax - arr[left]);
	        
	        lMax = max (lMax, arr[left]);
	        
	        left++;
	    }
	}
	
	return trap;
}

int main () {
	vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};

	cout << trapWater (arr);

	return 0;
}

/*

Trapping Rain Water

How much water is trapped above every bar after raining?

while (left <= right) 
	Every index (except the boundaries) should be processed

*/