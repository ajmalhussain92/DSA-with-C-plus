#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph (int v) {
        V = v;
        adj.resize(V);
    }

    void addEdge (int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // remove for directed
    }

    void dfs (int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs (neighbor, visited); // recursion (backtracking)
            }
        }
    }

    void startDFS () {
        vector<bool> visited (V, false);
        dfs (0, visited); // start from node 0
    }
};

int main () {
    Graph g (4);
    g.addEdge (0, 1);
    g.addEdge (0, 2);
    g.addEdge (1, 3);

    g.startDFS ();
}