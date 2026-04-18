#include <bits/stdc++.h>
using namespace std;

void dijkstra (int V, vector<pair<int,int>> adj[], int src) {
    
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<int> dist(V, INT_MAX);

    dist[src] = 0;
    pq.push ({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int weight = it.second;

            if(d + weight < dist[adjNode]) {
                dist[adjNode] = d + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    for (int i = 0; i < V; i++) 
        cout << "Distance from source to " << i 
             << " is " << dist[i] << endl;
}

/*

Time Complexity: O((V + E) log V)

*/
