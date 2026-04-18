#include <iostream>
using namespace std;


int find(int arr[]){
	int a = arr[0]+arr[1]+arr[2];
	int b = arr[3]+arr[4]+arr[5];
	int c = arr[6]+arr[7]+arr[8];
	
	if (a==b) {
		if (arr[6]>arr[7]) {
			return 6;
		}else if (arr[7]>arr[6]){
			return 7;
		}else if (arr[8] > arr[7]){
			return 8;					// Check last index, if there is an odd ball
		}
	} else if (a>b) {
		if (arr[0]>arr[1]) {
			return 0;
		} else if (arr[1]>arr[0]){
			return 1;
		}else {
			return 2;
		}
	}else if (b>a){
		if (arr[3]>arr[4]){
			return 3;
		}else if (arr[4]>arr[3]){
			return 4;
		}else {
			return 5;
		}
	}
	return -1;
}

int main () {
	
	int arr[9] = {1,1,1,1,1,1,1,1,1};
	
	int idx = find (arr);
	
	if (idx != -1)
		cout << "The odd ball: " << arr[idx];
	else 
		cout << "All balls are equal! ";
	
	return 0;
}