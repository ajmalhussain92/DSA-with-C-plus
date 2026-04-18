#include <iostream>
#include <vector>
using namespace std;

int calPoints(vector<string>& operations) {
	vector<int> record;
	for (const auto& op : operations) {
		if (op == "+") {
			int size = record.size();
			record.push_back(record[size - 1] + record[size - 2]);
		} else if (op == "D") {
			record.push_back(2 * record.back());
		} else if (op == "C") {
			record.pop_back();
		} else {
			// It's a number, then Record a new score
			record.push_back(stoi(op));
		}
	}
	int sum = 0;
	for (int score : record) {
		sum += score;
	}
	return sum;
}


int main () {
	vector<string> operations = {"5","2","C","D","+"};
    int res = calPoints (operations);
    cout << res;
}