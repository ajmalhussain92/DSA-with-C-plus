#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string addBinary (string a, string b) {
	string ans;

	int i = a.size() - 1;
	int j = b.size() - 1;

	int carry = 0;

	while (i >= 0 || j >= 0 || carry) {
		int sum = carry;

		if (i >= 0) sum += a[i--] - '0';
		if (j >= 0) sum += b[j--] - '0';

		ans += (sum % 2) + '0';
		carry = sum / 2;
	}

	reverse (ans.begin(), ans.end());
    
    // Remove the leading zeros
	int k = 0;
	while (k < ans.size() - 1 && ans[k] == '0')
		k++;

	return ans.substr(k);
}

int main () {
	string s1 = "1101", s2 = "111";
	cout << addBinary (s1, s2) << endl;

	return 0;
};