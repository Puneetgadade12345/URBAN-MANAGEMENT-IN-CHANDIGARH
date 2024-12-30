#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // Path compression
        return parent[x];
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // Union by rank
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

void kruskal(int V, vector<Edge>& edges) {
    DisjointSet ds(V);
    sort(edges.begin(), edges.end());

    vector<Edge> mst;
    int mstWeight = 0;

    for (auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;

        if (ds.find(u) != ds.find(v)) {
            ds.unionSet(u, v);
            mst.push_back(edge);
            mstWeight += edge.weight;
        }
    }

    cout << "Minimum Spanning Tree:" << endl;
    for (auto& edge : mst) {
        cout << edge.u << " - " << edge.v << ": " << edge.weight << endl;
    }
    cout << "Total weight: " << mstWeight << endl;
}

int main() {
    int V = 4;  // Number of vertices
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskal(V, edges);

    return 0;
}
