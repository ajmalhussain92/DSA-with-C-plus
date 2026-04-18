#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Majority Element (Optimal using Sorting)

int majorityElement(vector<int>& nums){
    int n = nums.size();
    
    sort(nums.begin(), nums.end());
    int freq = 0, num = nums[0];
    for(int i=0; i<n; i++){
        
        if(nums[i] == num){
            
            freq++;
        }else{
            
            num = nums[i];
            freq = 1;
        }
        
        if(freq > n/2){
            return nums[i];
        }
    }
    return -1;
}

int main(){
    
    vector<int> nums = {1, 3, 3, 1, 3};
    int mjEl = majorityElement(nums);
    cout<<"Majority element = "<<mjEl;
    
    return 0;
}

//	Time Complexity: O(nlogn)