#include<iostream>
#include<vector>
using namespace std;

vector<int> reversedArr(vector<int>& nums){
    int n = nums.size();
    int ptr1 = 0, ptr2 = n-1;		//Taking two pointers
    
    while(ptr1 <= ptr2){
        
        swap(nums[ptr1], nums[ptr2]);
        ptr1++, ptr2--;
    }
    return nums;
}

int main(){
    
    vector<int> nums = {1, 3, 5, 7, 6, 8, 11};
    reversedArr(nums);
    
    cout<<"Reversed array: ";
    for(int val : nums){
        
        cout<<val<<" ";
    }
    
    return 0;
}