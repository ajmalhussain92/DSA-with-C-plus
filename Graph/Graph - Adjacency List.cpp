#include <iostream>
#include <vector>
using namespace std;

/* Undirected Graph */

class Graph {
    int vertices;
    vector<vector<int>> adjList;

public:
    // Constructor
    Graph (int v) {
        vertices = v;
        adjList.resize(v);
    }

    // Add edge (undirected)
    void addEdge (int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);						// remove this for directed graph
    }

    // Display graph
    void display () {
        cout << "Adjacency List:\n";
        for (int i = 0; i < vertices; i++) {
            cout << i << " -> ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
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

Adjacency List Concept:
	? Instead of a matrix, each vertex stores a list of its neighbors.
	? Efficient for sparse graphs.

------------------------------

Adjacency List:
0 ? 1, 2  
1 ? 0, 3  
2 ? 0  
3 ? 1

------------------------------

For Directed Graph:
	Just remove one line:   adjList[v].push_back(u); // remove this

------------------------------

Traversal (BFS/DFS) is easier and faster
Space Complexity: O(V + E) ? (better than matrix)

------------------------------

Always prefer: 'vector<vector<int>>' for adjacency list.

*/