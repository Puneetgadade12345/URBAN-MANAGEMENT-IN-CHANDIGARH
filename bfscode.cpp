#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform BFS
void bfs(int V, vector<vector<int>>& adjList, int source) {
    vector<bool> visited(V, false); // To keep track of visited nodes
    queue<int> q;
    q.push(source);
    visited[source] = true;

    cout << "BFS Traversal starting from node " << source << ": ";

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adjList[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

int main() {
    int V, E;

    // Input graph details
    cout << "Enter the number of nodes (vertices): ";
    cin >> V;

    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> adjList(V);

    cout << "Enter the edges in the format <from_node> <to_node>:\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Undirected graph
    }

    int source;
    cout << "Enter the source node for BFS: ";
    cin >> source;

    // Perform BFS
    bfs(V, adjList, source);

    return 0;
}
