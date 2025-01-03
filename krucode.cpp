#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
using namespace std;

// Edge structure to store graph connections
struct Edge {
    int source, destination, weight;
};

// Disjoint Set Union (DSU) or Union-Find class
class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // Find operation with path compression
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    // Union operation by rank
    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

// Function to implement Kruskal's Algorithm
void kruskalMST(int vertices, vector<Edge>& edges) {
    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    DSU dsu(vertices);
    vector<Edge> mst;
    int mstCost = 0;

    // Process each edge
    for (Edge& edge : edges) {
        if (dsu.find(edge.source) != dsu.find(edge.destination)) {
            dsu.unite(edge.source, edge.destination);
            mst.push_back(edge);
            mstCost += edge.weight;
        }
    }

    // Output MST and its cost
    cout << "Minimum Spanning Tree (MST) edges:\n";
    for (Edge& edge : mst) {
        cout << "Edge: (" << edge.source << ", " << edge.destination << ") - Weight: " << edge.weight << "\n";
    }
    cout << "Total cost of MST: " << mstCost << "\n";
}

int main() {
    int vertices, edgesCount;

    // Example: Chandigarh ICT infrastructure input
    cout << "Enter the number of areas (vertices): ";
    cin >> vertices;
    cout << "Enter the number of connections (edges): ";
    cin >> edgesCount;

    vector<Edge> edges;

    cout << "Enter the connections (source, destination, weight):\n";
    for (int i = 0; i < edgesCount; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    // Call Kruskal's Algorithm
    kruskalMST(vertices, edges);

    return 0;
}

