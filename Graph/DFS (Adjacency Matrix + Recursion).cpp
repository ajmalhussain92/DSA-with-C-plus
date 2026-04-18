
void dfsMatrix (int node, int V, int adjMatrix[][100], bool visited[]) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < V; i++) {
        if (adjMatrix[node][i] == 1 && !visited[i]) {
            dfsMatrix (i, V, adjMatrix, visited);   // recursion (backtracking)
        }
    }
}