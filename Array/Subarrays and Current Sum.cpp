#include <iostream>
#include <vector>
using namespace std;

void generateSubarrays(vector<int>& arr){
    
    int n = arr.size();
    
    for(int i = 0; i < n; i++){
        int currSum = 0;
        
        for(int j = i; j < n; j++){
        	
            currSum += arr[j];
            cout<<"Subarray: [";
            
            for(int k = i; k <= j; k++){
                
                cout<<arr[k]<<(k == j? "" : ", ");
            }
            cout<<"] Sum = "<<currSum<<"\n";
        }
    }
}

int main(){
	
    vector<int> arr = {1, 2, 3, 4, 5};
    generateSubarrays(arr);
    return 0;
}