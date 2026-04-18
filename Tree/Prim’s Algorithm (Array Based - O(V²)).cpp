#include <bits/stdc++.h>
using namespace std;

int graph[10][10];
int n;

void prim() {

    int key[10];          // Minimum edge weight
    bool visited[10];     
    int parent[10];       // To store MST

    // Initialization
    for(int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    // Start from vertex 0
    key[0] = 0;

    for(int count = 0; count < n - 1; count++) {

        // Step 1: Pick minimum key vertex
        int min = INT_MAX, u;

        for(int i = 0; i < n; i++) {
            if(!visited[i] && key[i] < min) {
                min = key[i];
                u = i;
            }
        }

        visited[u] = true;

        // Step 2: Update adjacent vertices
        for(int v = 0; v < n; v++) {

            if(graph[u][v] != 0 &&
               !visited[v] &&
               graph[u][v] < key[v]) {

                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print MST
    cout << "Edge \t Weight\n";
    for(int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i 
             << "\t" << graph[parent[i]][i] << endl;
    }
}
