#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> countMap;
    int n = nums.size();

    for (int num : nums) {
        countMap[num]++;
        if (countMap[num] > n / 2) {
            return num; 
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {2, 2, 1, 2};
    int ans = majorityElement(nums);
    
    if (ans != -1)
        cout << "Majority element is: " << ans << endl;
    else
        cout << "No majority element found." << endl;
    
    return 0;
}