#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

typedef pair<int, int> pii;  // (weight, vertex)

void primsAlgorithm(const vector<vector<pii>>& graph, int V) {
    vector<int> key(V, INT_MAX);      // Stores the minimum edge weight for each vertex
    vector<int> parent(V, -1);        // Stores the parent of each vertex in the MST
    vector<bool> inMST(V, false);     // To check if a vertex is included in MST
    key[0] = 0;                       // Start from vertex 0

    priority_queue<pii, vector<pii>, greater<pii>> pq;  // Min-heap to extract minimum key vertex
    pq.push({0, 0});  // Start with vertex 0 and key value 0

    while (!pq.empty()) {
        int u = pq.top().second;  // Extract vertex with minimum key
        pq.pop();
        inMST[u] = true;  // Include u in MST

        // Explore the neighbors of u
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // If v is not in MST and the edge weight is smaller than the current key value
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    // Output the MST
    cout << "Edge \tWeight" << endl;
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " - " << i << " \t" << key[i] << endl;
    }
}

int main() {
    int V = 4;
    vector<vector<pii>> graph(V);

    // Graph represented by adjacency list (node, weight)
    graph[0].push_back({1, 1});  // A -> B with weight 1
    graph[1].push_back({0, 1});  // B -> A with weight 1

    graph[0].push_back({3, 3});  // A -> D with weight 3
    graph[3].push_back({0, 3});  // D -> A with weight 3

    graph[1].push_back({2, 2});  // B -> C with weight 2
    graph[2].push_back({1, 2});  // C -> B with weight 2

    graph[2].push_back({3, 4});  // C -> D with weight 4
    graph[3].push_back({2, 4});  // D -> C with weight 4

    // Run Prim's Algorithm to find MST starting from vertex 0
    primsAlgorithm(graph, V);

    return 0;
}
