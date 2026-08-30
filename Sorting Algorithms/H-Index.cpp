#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int hIndex (vector<int>& citations) {
	sort (citations.begin(), citations.end(), greater<int>());
	int h = 0;

	for (int i = 0; i < citations.size(); i++) {
		if (citations[i] >= i + 1)
			h = i + 1;
		else
			break;
	}

	return h;
}

int main () {
	vector<int> citations = {3, 0, 6, 1, 5};

	cout << hIndex (citations);

	return 0;
}

/*

H-index = maximum number h of papers that each have at least h citations

Kya mere paas H aise papers hain, jinke EACH ke paas kam-se-kam H citations hain?


*/