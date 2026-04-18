void dijkstra(int src) {

    int dist[10];
    bool visited[10];
    int predecessor[10];

    // Initialization
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        predecessor[i] = -1;
    }

    dist[src] = 0;

    // Run V-1 times
    for (int count = 0; count < n - 1; count++) {

        // Step 1: Find minimum distance unvisited vertex
        int min = INT_MAX, u;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = true;

        // Step 2: Relax adjacent vertices
        for (int v = 0; v < n; v++) {

            if (!visited[v] &&
                graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
                predecessor[v] = u;
            }
        }
    }

    // Print result
    for (int i = 0; i < n; i++) {
        cout << "Distance to " << i << " = " << dist[i] << endl;
    }
}

/*

Time Complexity: O(V²)

*/