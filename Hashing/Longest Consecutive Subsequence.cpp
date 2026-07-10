#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int longestConsecutive (vector<int> &arr) {
    unordered_set<int> st;
    int res = 0;

    // Hash all the array elements
    for (int val: arr)
        st.insert(val);

    for (int val: arr) {
      
        if (st.find (val-1) == st.end()) {
          
            int cur = val, cnt = 0;
            while (st.find (cur) != st.end()) {
                cur++;
              	cnt++;
            }

            res = max (res, cnt);
        }
    }
    
    return res;
}

int main () {
    vector<int> arr = {100, 4, 200, 1, 3, 2, 7};
    
    cout << longestConsecutive (arr);
    
    return 0;
}