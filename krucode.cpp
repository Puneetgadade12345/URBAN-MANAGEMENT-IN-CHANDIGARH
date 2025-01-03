#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

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
    int n;
    cout << "Enter the number of service centers: ";
    cin >> n;  // Get the number of service centers dynamically

    // Initialize the Disjoint Set Union (DSU) structure
    DSU dsu;

    // Add service centers to DSU
    cout << "Enter the names of the service centers:\n";
    vector<string> centers(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter name for service center " << i + 1 << ": ";
        cin >> centers[i];
        dsu.addNode(centers[i]);  // Add each service center to DSU
    }

    // Input edges (connections between service centers)
    int m;
    cout << "Enter the number of connections (roads): ";
    cin >> m;
    vector<Edge> edges(m);

    cout << "Enter the connections (service center 1, service center 2, and cost for each road):\n";
    for (int i = 0; i < m; i++) {
        cout << "Enter connection " << i + 1 << " (service center 1, service center 2, cost): ";
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Applying Kruskal's algorithm to find MST
    int mst_cost = kruskal(n, edges, dsu);
    cout << "Minimum Spanning Tree (MST) total cost: " << mst_cost << endl;

    return 0;
}
