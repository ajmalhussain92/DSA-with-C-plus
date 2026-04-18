#include <iostream>
#include <vector>
#include <climits>
using namespace std;
void pairElements(vector<int>& nums){
    int n = nums.size();
    cout<<"Pair Elements:\n";
    for(int i=0; i<n; i++){
        
        for(int j=i+1; j<n; j++){
            
            cout << "[" << nums[i] << "," << nums[j] << "]";
            cout << "\tSum = " << nums[i] + nums[j] << "\n";
        }
    }
}

int main(){
	
    vector<int> nums = {2, 7, 11, 15};
    pairElements(nums);
    
    return 0;
}