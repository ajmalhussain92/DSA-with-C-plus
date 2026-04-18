#include<iostream>
#include<vector>
using namespace std;
//Majority Element (Moore's Voting Algorithm)

int majorityElement(vector<int>& nums){
    int n = nums.size(), freq = 0, ans = 0;
    
    for(int i=0; i<n; i++){
        
        if(freq == 0){
        	
            ans = nums[i];
        }
        
        if(ans == nums[i]){
            freq++;
        }else{
            freq--;
        }
    }
    
    if(freq > 0){
        return ans;
    }else{
        return -1;
    }
}

int main(){
    
    vector<int> nums = {1, 3, 3, 1, 1};
    int res = majorityElement(nums);
    cout<<"Majority element = "<<res;
    
    return 0;
}

//	Time Complexity: O(n)
//	Space Complexity: O(1), as no extra space is used.