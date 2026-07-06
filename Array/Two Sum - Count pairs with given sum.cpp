#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

unordered_map<int, int> mp;

int countPairs (vector<int>& arr, int target) {
    
	unordered_map<int, int> freq;
	int count = 0;

	for (int i = 0; i < arr.size(); i++) {
        int need = target - arr[i];
        
		if (freq.find (need) != freq.end()) 
			count += freq[need];

		freq[arr[i]]++;
	}
	
	return count;
}

int main() {
	vector<int> arr = {1, 5, 7, -1, 5};
	int target = 6;

	cout << countPairs (arr, target);


	return 0;
}

/*

freq[arr[i]]++  is equivalent to  freq[10] = freq[10] + 1;

If key 10 doesn't exist:

    freq[10]   // creates {10 : 0}

then
    freq[10] = 0 + 1;

Result
    10 ? 1


*/