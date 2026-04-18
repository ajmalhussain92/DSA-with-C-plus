#include <iostream>
#include <vector>
using namespace std;
//Pair Elements
void pairElements(vector<int>& nums){
    int n = nums.size();
    
    for(int i=0; i<n; i++){
        
        for(int j=i+1; j<n; j++){
            cout<<nums[i]<<nums[j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
	
    vector<int> nums = {2, 7, 11, 15};
    cout<<"Pair elements in the array:\n";
	pairElements(nums);
    
    return 0;
}