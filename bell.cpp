#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>  // Include for std::reverse

using namespace std;

void bellmanFord(int source, const vector<vector<pair<int, int>>>& graph, const vector<string>& areaNames) {
    int n = graph.size();
    vector<int> distance(n, INT_MAX);
    vector<int> parent(n, -1);
    distance[source] = 0;

    // Relax all edges n-1 times
    for (int i = 1; i <= n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (const auto& neighbor : graph[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    parent[v] = u;
                }
            }
        }
    }

    cout << "\nShortest paths from \"" << areaNames[source] << "\" using Bellman-Ford:\n";
    vector<int> safeZones = {8, 9}; // Safe Zone A and B indices
    for (int safeZone : safeZones) {
        if (distance[safeZone] == INT_MAX) {
            cout << "No path available to \"" << areaNames[safeZone] << "\".\n";
        } else {
            vector<int> path;
            for (int at = safeZone; at != -1; at = parent[at]) {
                path.push_back(at);
            }
            std::reverse(path.begin(), path.end());  // Reverse the path to display from source to destination

            cout << "Path to \"" << areaNames[safeZone] << "\": ";
            for (size_t i = 0; i < path.size(); i++) {
                cout << areaNames[path[i]];
                if (i < path.size() - 1) cout << " -> ";
            }
            cout << "\nTotal Distance: " << distance[safeZone] << " km\n";
        }
    }
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

    int source;
    cout << "\nEnter the number corresponding to the affected area: ";
    cin >> source;

    if (source < 0 || source >= areaNames.size()) {
        cout << "Invalid input. Please enter a valid area number.\n";
    } else {
        bellmanFord(source, graph, areaNames);
    }

    return 0;
}
