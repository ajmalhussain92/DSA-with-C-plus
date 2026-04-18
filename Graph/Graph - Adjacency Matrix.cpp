#include <iostream>
using namespace std;

/* Undirected Graph */

class Graph {
    int vertices;
    int adjMatrix[100][100]; 				// fixed size for simplicity

public:
    // Constructor
    Graph (int v) {
        vertices = v;

        // Initialize matrix with 0
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    // Add edge (undirected)
    void addEdge (int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;				// remove this for directed graph
    }

    // Display matrix
    void display () {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main () {
    int v = 4;
    Graph g(v);

    g.addEdge (0, 1);
    g.addEdge (0, 2);
    g.addEdge (1, 3);

    g.display ();

    return 0;
}

/*

Adjacency Matrix Concept:
	● A graph with n vertices is represented by an n × n matrix.
	● If there is an edge between i and j, then:
			matrix[i][j] = 1
		otherwise: 
			matrix[i][j] = 0

------------------------------

Adjacency Matrix:
0 1 1 0
1 0 0 1
1 0 0 0
0 1 0 0

------------------------------

Vertices are indexed starting from 0.
	So if:
			int v = 5;
	The vertices will be: 0, 1, 2, 3, 4
			
------------------------------

Space Complexity: O(V²)

For Directed Graph:
	Just remove one line:   adjMatrix[v][u] = 1; // remove this

------------------------------

Dense - *Matrix*
Sparse - *List*

Pre-order - DFS
Level-order - BFS


*/