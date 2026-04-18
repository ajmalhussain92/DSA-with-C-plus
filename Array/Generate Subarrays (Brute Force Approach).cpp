#include <iostream>
#include <vector>
using namespace std;
//Generate Subarrays (Brute Force Approach)
void generateSubarrays(vector<int>& arr){
    
    int n = arr.size(), count = 0;
    
    for(int i = 0; i < n; i++){					//start
        
        for(int j = i; j < n; j++){				//end
            count++;
            cout<<"Subarray: [";
            for(int k = i; k <= j; k++){		//print elements
                
                cout<<arr[k]<<(k == j? "" : ", ");
            }
            cout<<"]\n";
        }
    }
    cout<<"Total subarrays are: "<<count;
}

int main(){
	
    vector<int> arr = {1, 2, 3, 4, 5};
    generateSubarrays(arr);
    return 0;
}
/*
Time Complexity : O(n3)
*/