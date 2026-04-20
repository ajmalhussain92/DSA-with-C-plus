#include <stack>

// DFS Iterative (Adjacency Matrix)
void dfsIterative (int node) {
	stack<int> st;
	st.push (node);
	visited[node] = true;

	while (!st.empty()) {
		int curr = st.top();
		st.pop();

		cout << curr << " ";

		for (int i = 0; i < vertices; i++) {
			if (!visited[i] && adjMatrix[curr][i] == 1) {
				st.push (i);
				visited[i] = true;
			}
		}
	}
}

// DFS Iterative (Adjacency List)
void dfsList (int node) {
	stack<int> st;
	st.push (node);
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


/*

DFS = Depth-First Search
DFS traversal = Pre-order traversal		(if we treat a Tree as a Graph)

DFS (Depth-First Search) in a graph is similar to pre-order traversal of a tree, but not strictly equivalent.

-----------------------------------------------------

Core Idea of DFS:
	Go as deep as possible -> then backtrack

-----------------------------------------------------

DFS Implementation:
	1. Using Recursion (Backtracking)
	2. Using Stack (Iterative)

-----------------------------------------------------

Graph Representation (How the graph is stored)
	1. Adjacency Matrix
	2. Adjacency List

-----------------------------------------------------

Combine Them -> 4 Possible Variants:

	Adjacency Matrix 	-> 	Recursion (Backtracking), Iterative (Stack)
	Adjacency List 		->	Recursion (Backtracking), Iterative (Stack)

*/