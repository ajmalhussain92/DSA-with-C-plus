#include <iostream>
#include <climits>
using namespace std;

int main(){
    
    int n = 4;
    int arr[n] = {2, -4, 5, 7};
    
    int maxSum = INT_MIN;
    
    cout << "All subarrays and their sums:\n\n";
    
    for(int start=0; start<n; start++){			//starting index
    	
        int currSum = 0;
        
        for(int end=start; end<n; end++){		//ending index
            
            currSum += arr[end];
            maxSum = max(currSum, maxSum);
            
            cout<<"Subarray: [";
            
            for(int i=start; i<=end; i++){				//print elements
                
                cout<<arr[i] << (i == end? "" : ", ");
            }
            cout<<"]\t\tSum = "<<currSum<<"\n";
        }
    }
    
    cout<<"\nMax sum of Subarray: "<<maxSum;
    
    return 0;
}

