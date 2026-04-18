#include <stack>

void dfsIterative (int start, vector<vector<int>>& adj) {
    vector<bool> visited (adj.size(), false);
    stack<int> st;

    st.push (start);

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    st.push (neighbor);
                }
            }
        }
    }
}