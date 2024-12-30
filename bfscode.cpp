#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

void bfs(int start, const vector<vector<int>>& graph) {
    // Create a queue for BFS
    queue<int> q;
    // Set of visited nodes
    unordered_set<int> visited;

    // Start from the given node
    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        // Dequeue a vertex from the queue
        int node = q.front();
        q.pop();
        cout << node << " ";

        // Get all adjacent vertices of the dequeued vertex
        for (int neighbor : graph[node]) {
            // If the neighbor hasn't been visited
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}

int main() {
    // Create a graph using adjacency list
    int V = 5;  // Number of vertices
    vector<vector<int>> graph(V);

    // Adding edges to the graph (undirected)
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(0);
    graph[1].push_back(3);
    graph[2].push_back(0);
    graph[2].push_back(4);
    graph[3].push_back(1);
    graph[4].push_back(2);

    // Perform BFS starting from vertex 0
    cout << "Breadth-First Search starting from node 0: ";
    bfs(0, graph);

    return 0;
}
