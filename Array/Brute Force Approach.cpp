#include <iostream>
#include <vector>
using namespace std;
//Brute Force Approach
void generateSubarrays(vector<int>& arr){
    
    int n = arr.size();
    
    for(int i = 0; i < n; i++){    			// Outer loop: start index 
        for(int j = i; j < n; j++){			// Inner loop: end index
            for(int k = i; k <= j; k++){
                
                cout<<arr[k];
            }
            cout<<" ";
        }
        cout<<"\n";							// Newline after each subarray
    }
}

int main(){
	
    vector<int> arr = {1, 2, 3, 4, 5};
    generateSubarrays(arr);
    return 0;
}
/*
Time Complexity : O(n3)
*/