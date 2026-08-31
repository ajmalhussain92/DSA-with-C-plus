#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int merge (vector<int> &arr, int lo, int mid, int hi) {
	int i = lo, j = mid + 1;
	int cnt = 0;

	vector<int> temp;

	while (i <= mid && j <= hi) {
		if (arr[i] <= arr[j]) {
			temp.push_back(arr[i++]);
		}
		else {
			cnt += mid - i + 1;
			temp.push_back(arr[j++]);
		}
	}

	while (i <= mid)
		temp.push_back(arr[i++]);

	while (j <= hi)
		temp.push_back(arr[j++]);

	for (int idx = 0; idx < temp.size(); idx++)
		arr[lo + idx] = temp[idx];

	return cnt;
}

int mergeSort (vector<int>& arr, int left, int right) {
	int cnt = 0;

	if (left < right) {
		int mid = left + (right - left) / 2;

		cnt += mergeSort (arr, left, mid);
		cnt += mergeSort (arr, mid + 1, right);

		cnt += merge (arr, left, mid, right);
	}

	return cnt;
}

int countInversion (vector<int>& arr) {
	return mergeSort (arr, 0, arr.size() - 1);
}

int main () {
	vector<int> arr = {24, 18, 38, 43, 14, 40, 1, 54};

	cout << countInversion (arr);

	return 0;
}

/*

Count Inversions of an Array

Goal: We can count inversions while performing Merge Sort.

Idea: Best use of Merge Sort

Inversion = a larger element appearing before a smaller element

Kya koi bada number, usse chhote number se pehle aa gaya hai?

*/