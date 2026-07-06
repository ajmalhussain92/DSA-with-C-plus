#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


// [Naive Approach] O(n^2) time and O(1) space
bool twoSum (vector<int>& arr, int target) {
    int n = arr.size();
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target)
                return true;
        }
    }
    
    return false;
}

//  Sorting and Two-Pointer Technique - O(n x log(n)) time and O(1) space
bool twoSum (vector<int>& arr, int target) {
    int n = arr.size();
    
    sort(arr.begin(), arr.end());
    
    int left = 0;
    int right = n - 1;
    
    while (left <= right) {
        if (arr[left] + arr[right] == target)
            return true;
        
        else if (arr[left] + arr[right] > target)
            right--;
        else
            left++;
    }
    
    return false;
}

// [Expected Approach] Hash Set - O(n) time and O(n) space
bool twoSum (vector<int>& arr, int target) {
    int n = arr.size();
    
    unordered_set<int> s;
    
    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];
        
        if (s.find (complement) != s.end())
            return true;
        
        s.insert (arr[i]);
    }
    
    return false;
}

int main() {
    vector<int> arr = {0, -1, 2, -5, 1};
    int target = -2;
    
    cout << twoSum (arr, target);

    return 0;
}