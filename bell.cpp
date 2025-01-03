#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void bellmanFord(int V, int E, vector<vector<int>>& edges, int source) {
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    // Relax all edges (V-1) times
    for (int i = 1; i < V; ++i) {
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], weight = edge[2];
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains a negative-weight cycle.\n";
            return;
        }
    }

    // Print the shortest distances
    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < V; ++i) {
        if (dist[i] == INT_MAX)
            cout << "Node " << i << ": Unreachable\n";
        else
            cout << "Node " << i << ": " << dist[i] << "\n";
    }
}

int main() {
    int V, E;

    cout << "Enter the number of vertices: ";
    cin >> V;

    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> edges;

    cout << "Enter the edges in the format <from_node> <to_node> <weight>:\n";
    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back({u, v, weight});
    }

    int source;
    cout << "Enter the source node: ";
    cin >> source;

    bellmanFord(V, E, edges, source);

    return 0;
}
