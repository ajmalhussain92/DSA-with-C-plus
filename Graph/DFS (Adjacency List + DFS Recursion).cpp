#include <iostream>
#include <vector>
using namespace std;

/* DFS (Adjacency List + DFS Recursion) */

class Graph {
    int vertices;
    vector<vector<int>> adjList;
    vector<bool> visited;

public:
    Graph (int v) {
        vertices = v;
        adjList.resize (v);
        visited.resize (v, false);
    }
    
    void addEdge (int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);            // remove for directed
    }
    
    void display () {
        for (int i = 0; i < vertices; i++) {
            cout << i << " : ";
            for (auto j : adjList[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
    
    // DFS Recursion (Adjacency List)
    void dfsList (int node) {
        cout << node << " ";
        visited[node] = true;

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfsList (neighbor);         // recursion (backtracking)
            }
        }
    }
};

int main () {
	Graph g(4);
	g.addEdge (0, 1);
	g.addEdge (0, 2);
	g.addEdge (1, 3);
	
	cout << "\nGraph using Adjacency List: \n";
    g.display ();
    
    cout << "\nDFS Traversal: \n";
    g.dfsList(0);               			// start from node 0
    
	return 0;
}