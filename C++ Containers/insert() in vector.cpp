#include <iostream>
#include <vector>

using namespace std;

int main () {
	vector<int> res = {2, 5, 9, 3};
	vector<int> leftRes = {3, 9, 11, 13, 20};

	res.insert (res.end(), leftRes.begin(), leftRes.end());
	
	for (auto x : res) cout << x << " ";

	return 0;
}

/*

insert (position, start_iterator, end_iterator)

*/