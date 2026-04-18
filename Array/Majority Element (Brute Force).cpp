#include<iostream>
#include<vector>
using namespace std;
//Majority Element (Brute Force)
int majorityElement(vector<int> nums){
    int n = nums.size();
    
    for(int val : nums){
        int freq = 0;
        
        for(int el : nums){
            
            if(el == val){
                freq++;
            }
        }

        if(freq > n/2){			//freq more than half
            return val;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {2, 1, 1, 2, 1};
    
    int mjEl = majorityElement(arr);
    cout<<"Majority Element = "<<mjEl;
    
    return 0;
}

/*	Time Complexity: O(n2)

int majorityElement(vector<int>& nums){
    int n = nums.size();
    
    for(int i=0; i<n; i++){
        int freq=0;
        for(int j=0; j<n; j++){
            
            if(nums[i] == nums[j]){
                
                freq++;
            }
            if(freq > n/2){
                
                return nums[i];
            }
        }
    }
    return -1;
}

*/