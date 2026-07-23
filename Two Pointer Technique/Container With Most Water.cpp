#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int maxWater (vector<int>& arr) {

	int left = 0;
	int right = arr.size() - 1;
	
	int max_area = 0;
	
	while (left < right) {
	    int height = min (arr[left], arr[right]);
	    int width = right - left;
	    
	    int area = height * width;
	    
	    max_area = max (max_area, area);
	    
	    if (arr[left] < arr[right])
	        left++;
	    else
	        right--;
	}
	
	return max_area;
}

int main () {
	vector<int> arr = {1,8,6,2,5,4,8,3,7};

	cout << maxArea (arr);
	
	
	return 0;
}

/*


Container With Most Water

Choose any two lines to form one container with the maximum area.
Water will spill over the shorter wall, Therefore:

	Area = Width x min(arr[left], arr[right])

where,

	Width = distance between the two lines.
	Height = the shorter of the two lines.
	
---------------------------------------------------------
int width = right - left;
int height = min(arr[left], arr[right]);

int area = width * height;

*/