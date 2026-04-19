/* Directed + Weighted Graph */


/* 1. Adjacency Matrix (Weighted):  */

int adjMatrix[5][5];

// Initialize
for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
        adjMatrix[i][j] = 0; // or INF if no edge
    }
}

// Add directed weighted edge u -> v
adjMatrix[u][v] = weight;


// ============================================================  //


/* 2. Adjacency List (Weighted): */

vector<pair<int, int>> adjList[5];

// Add directed weighted edge
adjList[u].push_back ({v, weight});

/*

A graph can be directed + weighted, and you can represent it using either Adjacency Matrix or Adjacency List.
The choice depends mainly on dense or sparse.

-----------------------------------------

How to store WEIGHT?

1. Adjacency Matrix (Weighted)
	Instead of 0/1, store weight:

2. Adjacency List (Weighted)
	Use pair (neighbor, weight):

-----------------------------------------

Directed + Weighted Example:

Graph:
0 ? 1 (5)
0 ? 2 (3)
1 ? 3 (2)

Matrix:
0  5  3  0
0  0  0  2
0  0  0  0
0  0  0  0

List:
0 ? (1,5), (2,3)
1 ? (3,2)
2 ? 
3 ?

-----------------------------------------

Use Adjacency Matrix when:
	? Graph is dense (many edges)
	? Need fast edge lookup ? O(1)
	? Memory is not a problem

Use Adjacency List when:
	? Graph is sparse (few edges) (most common)
	? Want better space efficiency
	? Used in most algorithms (BFS, DFS, Dijkstra)

*/