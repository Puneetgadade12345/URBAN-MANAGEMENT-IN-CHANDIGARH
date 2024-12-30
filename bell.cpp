#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Function to implement Bellman-Ford algorithm
void bellmanFord(const vector<Edge>& edges, int V, int E, int src) {
    // Step 1: Initialize distances from src to all other vertices as INFINITE
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Step 2: Relax all edges V-1 times
    for (int i = 1; i < V; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Step 3: Check for negative weight cycles
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int weight = edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle\n";
            return;
        }
    }

    // Step 4: Print the shortest distances from the source
    cout << "Vertex   Distance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << " \t\t " << dist[i] << endl;
    }
}

int main() {
    int V = 5; // Number of vertices
    int E = 8; // Number of edges

    // Define the edges: u, v, weight
    vector<Edge> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    int src = 0; // Source vertex
    bellmanFord(edges, V, E, src);

    return 0;
}
