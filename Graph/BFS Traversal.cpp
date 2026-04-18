#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100; // Maximum number of vertices

void bfsUsingQueue (int startNode, int adjMatrix[][MAX], int V, bool visited[]) {
    queue<int> q;
    q.push (startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        // Visit all adjacent nodes
        for (int i = 0; i < V; ++i) {
            if (adjMatrix[node][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main () {
    int V = 5; // Number of vertices
    int adjMatrix[MAX][MAX] = {0};

    // Sample undirected graph:
    // 0 - 1, 0 - 2
    // 1 - 3
    // 2 - 4
    adjMatrix[0][1] = adjMatrix[1][0] = 1;
    adjMatrix[0][2] = adjMatrix[2][0] = 1;
    adjMatrix[1][3] = adjMatrix[3][1] = 1;
    adjMatrix[2][4] = adjMatrix[4][2] = 1;

    bool visited[MAX] = {false};

    cout << "BFS traversal starting from node 0:\n";
    bfsUsingQueue (0, adjMatrix, V, visited);

    return 0;
}


