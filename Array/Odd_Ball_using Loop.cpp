#include <iostream>
using namespace std;

int find(int arr[], int len){
	
	for (int i=0; i<len; i++){
		if (arr[i] > arr[i+1])
			return i;
	}
	return -1;
}
int main () {
	
	int arr[9] = {1,1,1,1,1,1,1,1,1};
	
	int idx = find (arr, 9);
	
	if (idx != -1)
		cout << "The odd ball: " << arr[idx];
	else 
		cout << "All balls are equal! ";
	
	return 0;
}