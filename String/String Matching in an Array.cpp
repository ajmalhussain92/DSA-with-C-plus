#include <iostream>
#include <vector>
using namespace std;

// find() mehtod, Time: O(n² · m)
vector<string> stringMatching (vector<string>& words) {
	vector<string> res;

	for (int i = 0; i < words.size(); i++) {
		for (int j = 0; j < words.size(); j++) {

			if (i != j && words[j].find (words[i]) != string::npos) {
				res.push_back (words[i]);
				break;
			}
		}
	}

	return res;
}

// KMP mehtod, Time: O(n² · m)
void buildLPS (string pattern, vector<int>& lps) {
	int m = pattern.length();
	int len = 0;
	lps[0] = 0;

	int i = 1;

	while (i < m) {
		if (pattern[i] == pattern[len]) {
			len++;
			lps[i] = len;
			i++;
		} else {
			if (len != 0)
				len = lps[len - 1];
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
}

bool KMPsearch (string text, string pattern) {
	int n = text.length();
	int m = pattern.length();

	vector<int> lps(m);
	buildLPS(pattern, lps);

	int i = 0, j = 0;
	while (i < n) {

		if (text[i] == pattern[j]) {
			i++;
			j++;
		}

		if (j == m)
			return true;
		else if (i < n && text[i] != pattern[j]) {

			if (j != 0)
				j = lps[j - 1];
			else
				i++;
		}
	}
	return false;
}

vector<string> stringMatching (vector<string>& words) {
	int n = words.size();
	vector<string> ans;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (i == j)
				continue;

			if (KMPsearch(words[j], words[i])) {
				ans.push_back(words[i]);
				break;
			}
		}
	}

	return ans;
}

int main() {
	vector<string> words = {"mass","as","hero","superhero"};
	
	vector<string> ans = stringMatching (words);
	
	for (string s : ans) cout << s << " ";

	return 0;
}