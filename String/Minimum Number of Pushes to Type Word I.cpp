

// Time: O(n), Space: O(1)
int minimumPushes(string word) {
	int n = word.size();
	int ans = 0;

	for (int i = 0; i < n; ++i) 
		ans += i / 8 + 1;

	return ans;
}


// Time: O(1), Space: O(1)
int minimumPushes (string word) {
	int n = word.size();
	int m = (n - 1) / 8 + 1;
	return m * (m - 1) * 4 + (n - (m - 1) * 8) * m;
}


int main () {
	string s = "pqrs";

	cout << minimumPushes (s);

	return 0;
}

/*

3014. Minimum Number of Pushes to Type Word I

First 8 letters 	? 1 push each
Second 8+ letters 	? 2 push each
Third 16+ letters 	? 3 push each

... and so on.





*/