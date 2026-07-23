#include <iostream>
#include <vector>
using namespace std;

int countTriplets (vector<int> &arr, int target) {
	int n = arr.size();
	
	sort(arr.begin(), arr.end());

	int count = 0;

	for (int i = 0; i < n - 2; i++) {
	    
		int left = i + 1;
		int right = n - 1;
		
		while (left < right) {
		    
		    int sum = arr[i] + arr[left] + arr[right];
		    
		    if (sum < target)
		        left++;
		    
		    else if (sum > target)
		        right--;
		    
		    else {
		        if (arr[left] == arr[right]) {
		            
		            int m = right - left + 1;
		            count += m * (m - 1)/2;
		            break;
		        }
		        
		        int leftCount = 1;
		        while (left + 1 < right && arr[left] == arr[left + 1]) {
		            leftCount++;
		            left++;
		        }
		        
		        int rightCount = 1;
		        while (right - 1 > left && arr[right] == arr[right - 1]) {
		            rightCount++;
		            right--;
		        }
		        
		        count += leftCount * rightCount;
		        
		        left++;
		        right--;
		    }
		}
	}
	
	return count;
}

int main() {
	vector<int> arr = {-3, -1, -1, 0, 1, 2};
	int target = -2;

	cout << countTriplets (arr, target) << endl;
	return 0;
}