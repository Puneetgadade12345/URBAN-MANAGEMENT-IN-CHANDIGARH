#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <string>

using namespace std;

void primsMST(const vector<vector<pair<int, int>>>& graph, const vector<string>& areaNames) {
    int n = graph.size();
    vector<int> parent(n, -1);
    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);
    key[0] = 0; // Start with node 0
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;

        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    cout << "\nMinimum Spanning Tree (MST) using Prim's Algorithm:\n";
    int totalWeight = 0;
    for (int i = 1; i < n; i++) {
        if (parent[i] != -1) {
            cout << areaNames[parent[i]] << " -> " << areaNames[i] << " with weight " << key[i] << " km\n";
            totalWeight += key[i];
        }
    }
    cout << "Total Weight of MST: " << totalWeight << " km\n";
}

int main() {
    vector<string> areaNames = {
        "Sector 17 (Chandigarh City Center)",
        "Sector 22 (Chandigarh Market)",
        "PGI Hospital (Chandigarh)",
        "Chandigarh Railway Station",
        "Chandigarh Airport",
        "Sector 35 (Chandigarh Residential Area)",
        "Flood-Affected Area (Chandigarh)",
        "Earthquake-Affected Area (Chandigarh)",
        "Safe Zone A (Northwest Cities)",
        "Safe Zone B (Southeast Cities)"
    };

    vector<vector<pair<int, int>>> graph = {
        {{1, 4}, {2, 2}}, // Sector 17 to Sector 22, PGI Hospital
        {{0, 4}, {2, 5}, {3, 10}}, // Sector 22 to Sector 17, PGI, Railway Station
        {{0, 2}, {1, 5}, {3, 3}}, // PGI to Sector 17, Sector 22, Railway Station
        {{1, 10}, {2, 3}, {4, 11}}, // Railway Station to Sector 22, PGI, Airport
        {{3, 11}, {5, 6}}, // Airport to Railway Station, Sector 35
        {{4, 6}} // Sector 35 to Airport
    };

    cout << "--- Disaster Management System for Chandigarh ---\n";
    cout << "Available areas:\n";
    for (size_t i = 0; i < areaNames.size(); i++) {
        cout << i << ": " << areaNames[i] << "\n";
    }

    primsMST(graph, areaNames);

    return 0;
}


