#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/* DFS (Adjacency List + DFS Iterative) */

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

	// DFS Iterative (Adjacency List)
	void dfsList (int node) {
		stack<int> st;
		st.push(node);
		visited[node] = true;

		while (!st.empty()) {
			int curr = st.top();
			st.pop();
			
			cout << curr << " ";

			for (int neighbor : adjList[curr]) {
				if (!visited[neighbor]) {
					st.push (neighbor);
					visited[neighbor] = true;
				}
			}
		}
	}
};

int main () {
	Graph g(8);

	g.addEdge (0, 1);
	g.addEdge (0, 2);
	g.addEdge (1, 3);
	g.addEdge (1, 4);
	g.addEdge (2, 4);
	g.addEdge (2, 6);
	g.addEdge (2, 5);
	g.addEdge (7, 5);
	g.addEdge (7, 6);

	cout << "\nGraph using Adjacency List: \n";
	g.display ();

	cout << "\nDFS Traversal: \n";
	g.dfsList(0);               			// start from node 0

	return 0;
}