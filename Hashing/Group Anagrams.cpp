#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams (vector<string>& arr) {

	unordered_map<string, vector<string>> mp;

	for (string word : arr) {

		string key = word;
		sort (key.begin(), key.end());

		mp[key].push_back(word);
	}

	vector<vector<string>> ans;

	for (auto &it : mp)
		ans.push_back (it.second);

	return ans;
}

int main () {
	vector<string> arr = {"act", "god", "cat", "dog", "tac"};

	vector<vector<string>> res = groupAnagrams (arr);

	for (const auto& row : res) {
		for (string s : row) {
			cout << s << " ";
		}
		cout << "\n";
	}

	return 0;
}

/*

All anagrams become identical after sorting their characters.

Example

    act
    cat
    tac

Sort each string:

    act -> act
    cat -> act
    tac -> act

Similarly,

    god -> dgo
    dog -> dgo

----------------------------------------------------------
Step 1: Create a Hash Map
unordered_map<string, vector<string>> mp;

Here,

    Key = Sorted string
    Value = List of original strings

----------------------------------------------------------
Hash map looks like:
{
    "act" : ["act","cat","tac"],
    "dgo" : ["god","dog"]
}


*/