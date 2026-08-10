#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int maxTasks(vector<int>& h, vector<int>& l) {
	int n = h.size();

	vector<int> dp(n + 1, 0);

	// Day 0
	dp[1] = max(h[0], l[0]);

	for (int i = 1; i < n; i++) {
		// Low effort today
		int low = dp[i] + l[i];

		// High effort today
		// Previous day must be a no-task day.
		int high = h[i];

		if (i >= 2)
			high += dp[i - 1];

		dp[i + 1] = max({dp[i], low, high});
	}

	return dp[n];
}

/*

High Effort vs Low Effort

Think about the decision on each day

For day i, there are essentially two useful states:

dp[i] = maximum tasks we can complete up to day i.
If we choose a high-effort task on day i, then day i-1 must have been a no-task day.

So for day i, we have three possibilities:

Do nothing today
? dp[i-1]
Do low-effort today
? dp[i-1] + l[i]
Do high-effort today
? We cannot have worked on day i-1, so we need the best answer up to i-2:
? dp[i-2] + h[i]

Therefore:

dp[i]=max(dp[i-1], dp[i-1]+l[i], dp[i-2]+h[i])

For i = 0, high effort is allowed directly.

*/