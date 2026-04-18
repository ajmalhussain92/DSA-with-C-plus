#include <iostream>
#include <vector>
using namespace std;
//Pair Elements and Pair Sum
vector<int> findPair(vector<int>& nums, int target){
    int n = nums.size();
    vector<int> ans;
    
    for(int i=0; i<n; i++){
        
        for(int j=i+1; j<n; j++){
            
            if(nums[i] + nums[j] == target){
                
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}

int main(){
	
    vector<int> nums = {2, 7, 11, 15};
    int target = 22;
    
    vector<int> ans = findPair(nums, target);
    cout<<"Indexes are: "<<ans[0]<<" "<<ans[1];
    return 0;
}
/*
Time Complexity: O(n2)

*/