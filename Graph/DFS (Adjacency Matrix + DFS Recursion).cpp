#include <iostream>
#include <vector>
using namespace std;

class Graph {
	int vertices;
	int adjMatrix[100][100];			// Adjacency Matrix
	vector<bool> visited;

public:
	Graph (int v) {
		vertices = v;
		visited.resize(v, false);

		// Initialize matrix with 0
		for (int i = 0; i < vertices; i++) {
			for (int j = 0; j < vertices; j++) {
				adjMatrix[i][j] = 0;
			}
		}
	}

	void addEdge (int u, int v) {
		adjMatrix[u][v] = 1;
		adjMatrix[v][u] = 1;            // remove for directed
	}

	void display () {
		for (int i = 0; i < vertices; i++) {
			for (int j = 0; j < vertices; j++) {
				cout << adjMatrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	
	// DFS Recursion (Adjacency Matrix)
	void dfsMatrix (int node) {
        visited[node] = true;
        cout << node << " ";
        
        for (int i = 0; i < vertices; i++) {
            if (!visited[i] && adjMatrix[node][i] == 1) {
                dfsMatrix (i);          // recursion (backtracking)
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

	cout << "\nGraph using Adjacency Matrix: \n";
	g.display ();

	cout << "\nDFS Traversal: \n";
	g.dfsMatrix(0);               // start from node 0

	return 0;
}

/*

Instead 'int adjMatrix[100][100];', we can use 'vector<vector<int>> adjMatrix;'

    Benefit:
        Flexible size
        Less memory use

-----------------------------

Another Important Note:
    We can Reset visited (if reused):
        fill(visited.begin(), visited.end(), false);

*/