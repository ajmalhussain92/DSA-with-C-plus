#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

vector<vector<int>> shiftGrid (vector<vector<int>>& grid, int k) {
	int n = grid.size();
	int m = grid[0].size();

	vector<vector<int>> res(n, vector<int>(m));

	// Total number of elements
	int total = n * m;

	// If k is greater than total elements
	k %= total;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			// Convert (i, j) to 1D index
			int idx = i * m + j;

			// New position after k shifts
			int newIdx = (idx + k) % total;

			// Convert back to 2D coordinates
			int newRow = newIdx / m;
			int newCol = newIdx % m;

			// Place the element
			res[newRow][newCol] = grid[i][j];
		}
	}

	return res;
}

int main () {
	vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};
	int k = 1;


	vector<vector<int>> res = shiftGrid (grid, k);
	
	for (const auto& row : res) {
	    for (const auto& element: row) {
	        cout << element << " ";
	    }
	    
	    cout << "\n";
	}

	return 0;
}

/*

1 2 3 4 5 6 7 8 9 After one shift: 		9 1 2 3 4 5 6 7 8

So the grid behaves exactly like a 1D circular array

For a cell (i, j), its 1D index is:		idx = i * m + j;

After k shifts: 						newIdx = (idx + k) % (n * m);

Convert back:

newRow = newIdx / m;
newCol = newIdx % m;


Now simply place:						res[newRow][newCol] = grid[i][j];

*/