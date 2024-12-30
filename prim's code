#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the vertex with the minimum key value
int minKey(const vector<int>& key, const vector<bool>& inMST, int V) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < V; v++) {
        if (!inMST[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to implement Prim's algorithm
void primMST(const vector<vector<int>>& graph, int V) {
    vector<int> parent(V, -1);   // Array to store the constructed MST
    vector<int> key(V, INT_MAX);  // Key values used to pick minimum weight edge
    vector<bool> inMST(V, false); // To represent the vertices included in MST
    
    key[0] = 0; // Start from the first vertex
    parent[0] = -1; // First node is always the root of MST

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, inMST, V); // Pick the minimum key vertex not yet included in MST

        inMST[u] = true; // Include vertex u in MST

        // Update the key and parent values of adjacent vertices of the picked vertex u
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the constructed MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
    }
}

int main() {
    int V = 5;
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph, V);
    return 0;
}
