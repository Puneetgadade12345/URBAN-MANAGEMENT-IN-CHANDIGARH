#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    string u, v;
    int weight;
    
    bool operator<(const Edge &e) {
        return weight < e.weight;
    }
};

// Class to represent Disjoint Set Union (DSU)
class DSU {
public:
    map<string, string> parent;
    map<string, int> rank;

    // Find the representative of the set to which element x belongs
    string find(string x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // Path compression
        return parent[x];
    }

    // Union of two subsets
    void unite(string x, string y) {
        string rootX = find(x);
        string rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    void addNode(string node) {
        parent[node] = node;
        rank[node] = 0;
    }
};

// Kruskal's algorithm to find the Minimum Spanning Tree (MST)
int kruskal(int n, vector<Edge>& edges, DSU& dsu) {
    int mst_weight = 0;

    // Sort edges by weight
    sort(edges.begin(), edges.end());

    // Process each edge and apply union-find to avoid cycles
    for (Edge& edge : edges) {
        string u = edge.u, v = edge.v;
        int weight = edge.weight;
        if (dsu.find(u) != dsu.find(v)) {
            dsu.unite(u, v);
            mst_weight += weight;
            cout << "Road between " << u << " and " << v << " with cost " << weight << " included in MST.\n";
        }
    }

    return mst_weight;
}

int main() {
    // Number of service centers in Chandigarh
    int n = 6;  // Example: 6 service centers

    // Initialize the Disjoint Set Union (DSU) structure
    DSU dsu;
    dsu.addNode("Sector 17");
    dsu.addNode("Sector 22");
    dsu.addNode("Sector 34");
    dsu.addNode("Sector 35");
    dsu.addNode("Sector 43");
    dsu.addNode("Sector 45");

    // Vector to store all edges (service center connections with cost)
    vector<Edge> edges = {
        {"Sector 17", "Sector 22", 4}, {"Sector 17", "Sector 34", 3}, {"Sector 22", "Sector 34", 1},
        {"Sector 22", "Sector 35", 2}, {"Sector 34", "Sector 35", 4}, {"Sector 34", "Sector 43", 5},
        {"Sector 35", "Sector 43", 2}, {"Sector 43", "Sector 45", 6}
    };

    // Applying Kruskal's algorithm to find MST
    int mst_cost = kruskal(n, edges, dsu);
    cout << "Minimum Spanning Tree (MST) total cost: " << mst_cost << endl;

    return 0;
}
