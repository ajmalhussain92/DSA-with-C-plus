#include<iostream>
#include<vector>
#include<climits>
using namespace std;
//Kadane's Algorithm
int Kadanes(vector <int> vec){
	int n = vec.size();
    int maxSum = INT_MIN, currSum = 0;
    
    for(int i=0; i<n; i++){
        
        currSum += vec[i];
        maxSum = max(currSum, maxSum);
        
        if(currSum < 0){
            currSum = 0;
        }
    }
    return maxSum;
}

int main(){
    
    vector <int> nums = {-1, 3, 1, -2};
    
    int maxSum = Kadanes(nums);
    
    cout<<"Max Sum = "<<maxSum;
    
    return 0;
}

/*
Time Complexity: O(n)
	
*/