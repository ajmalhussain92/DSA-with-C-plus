#include <iostream>
#include <vector>
//Unique Elements in Array
using namespace std;
int uniqueElement(vector<int>& nums){
    int ans = 0;
    for(int val : nums){
        
        ans = ans ^ val;
    }
    return ans;
}

int main(){
    
    vector<int> vec = {7, 2,7,2,9};
    
    int res = uniqueElement(vec);
    
    cout << "Unique no: "<<res;
    
    return 0;
}