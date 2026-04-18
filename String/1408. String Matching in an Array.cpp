#include <iostream>
#include <vector>
using namespace std;


int main () {
	vector<string> words = {"mass","as","hero","superhero","leetcode","et","code"};


	vector<string> found;

	for (int i = 0; i < words.size(); i++) {
		for (int j = 0; j < words.size(); j++) {

			if (i != j && words[j].find(words[i]) != string::npos) {
				found.push_back (words[i]);
				break;
			}
		}
	}
	
	cout << "All found strings, and substrings in the words\n";
    for (string s : found) cout << s << " ";

	return 0;
}