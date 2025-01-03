#include <iostream>
#include <vector>
using namespace std;

// Structure to represent an edge
struct Edge {
    int source, destination, weight;
};

// Function to partition edges for Quick Sort
int partition(vector<Edge>& edges, int low, int high) {
    int pivot = edges[high].weight; // Pivot element
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (edges[j].weight <= pivot) {
            ++i;
            swap(edges[i], edges[j]);
        }
    }
    swap(edges[i + 1], edges[high]);
    return i + 1;
}

// Quick Sort function for edges
void quickSort(vector<Edge>& edges, int low, int high) {
    if (low < high) {
        int pi = partition(edges, low, high);
        quickSort(edges, low, pi - 1);
        quickSort(edges, pi + 1, high);
    }
}

// Find function for union-find (DSU)
int findParent(vector<int>& parent, int vertex) {
    if (parent[vertex] != vertex)
        parent[vertex] = findParent(parent, parent[vertex]);
    return parent[vertex];
}

// Union function for union-find (DSU)
void unionVertices(vector<int>& parent, vector<int>& rank, int u, int v) {
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);

    if (rank[rootU] > rank[rootV]) {
        parent[rootV] = rootU;
    } else if (rank[rootU] < rank[rootV]) {
        parent[rootU] = rootV;
    } else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}

int main() {
    int vertices, edgesCount;
    cout << "Enter the number of areas (vertices): ";
    cin >> vertices;
    cout << "Enter the number of connections (edges): ";
    cin >> edgesCount;

    vector<Edge> edges(edgesCount);

    cout << "Enter the connections (source, destination, weight):\n";
    for (int i = 0; i < edgesCount; ++i) {
        cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }

    // Sort edges using Quick Sort
    quickSort(edges, 0, edgesCount - 1);

    // Perform union-find to determine MST
    vector<int> parent(vertices), rank(vertices, 0);
    for (int i = 0; i < vertices; ++i) {
        parent[i] = i;
    }

    vector<Edge> mst;
    int totalCost = 0;

    for (const auto& edge : edges) {
        int rootU = findParent(parent, edge.source);
        int rootV = findParent(parent, edge.destination);

        if (rootU != rootV) {
            mst.push_back(edge);
            totalCost += edge.weight;
            unionVertices(parent, rank, rootU, rootV);
        }
    }

    // Display results
    cout << "\nMinimum Spanning Tree (MST) edges:\n";
    for (const auto& edge : mst) {
        cout << "Edge: (" << edge.source << ", " << edge.destination << ") - Weight: " << edge.weight << "\n";
    }
    cout << "Total cost of MST: " << totalCost << "\n";

    return 0;
}
