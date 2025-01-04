#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <string>
#include <algorithm> // For reverse

using namespace std;

// Function to find the shortest paths from a source to all destinations using Dijkstra's Algorithm
void dijkstra(int source, const vector<vector<pair<int, int>>>& graph, const vector<string>& areaNames, const vector<vector<string>>& safeZoneDetails) {
    int n = graph.size();
    vector<int> distance(n, INT_MAX); // Initialize distances as infinity
    vector<int> parent(n, -1);        // To track the path
    distance[source] = 0;

    // Min-heap priority queue to store {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Skip if the current distance is not optimal
        if (dist > distance[node]) continue;

        // Explore neighbors
        for (const auto& neighbor : graph[node]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;

            if (distance[node] + weight < distance[nextNode]) {
                distance[nextNode] = distance[node] + weight;
                parent[nextNode] = node;
                pq.push({distance[nextNode], nextNode});
            }
        }
    }

    // Output the shortest paths to all safe zones
    cout << "\nShortest paths from \"" << areaNames[source] << "\" to all safe zones:\n";

    // Safe zone indices
    vector<int> safeZones = {8, 9}; // Indices of "Safe Zone A" and "Safe Zone B"
    for (int safeZone : safeZones) {
        if (distance[safeZone] == INT_MAX) {
            cout << "No path available to \"" << areaNames[safeZone] << "\".\n";
        } else {
            vector<int> path;
            for (int at = safeZone; at != -1; at = parent[at]) {
                path.push_back(at);
            }
            reverse(path.begin(), path.end());

            cout << "Path to \"" << areaNames[safeZone] << "\": ";
            for (size_t i = 0; i < path.size(); i++) {
                cout << areaNames[path[i]];
                if (i < path.size() - 1) cout << " -> ";
            }
            cout << "\nTotal Distance: " << distance[safeZone] << " km\n";

            // Display safest zones (nearest cities and within-city safe zones)
            cout << "Safest zones (nearest cities and within-city zones) within \"" << areaNames[safeZone] << "\":\n";
            for (const string& subZone : safeZoneDetails[safeZone - 8]) {
                cout << " - " << subZone << "\n";
            }
        }
    }
}

int main() {
    // Area names in Chandigarh with real-world areas
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

    // Safe zone details with nearest cities and within-city safe zones
    vector<vector<string>> safeZoneDetails = {
        {"Mohali", "Panchkula", "Kalka", "Ambala", "Kurukshetra", "Chandigarh Sector 17", "Chandigarh Sector 22", "Chandigarh Sector 35"}, // Safe Zone A (Northwest cities and within-city)
        {"Ludhiana", "Jalandhar", "Patiala", "Bathinda", "Sirsa", "Chandigarh Sector 40", "Chandigarh Sector 42", "Chandigarh Sector 45"}  // Safe Zone B (Southeast cities and within-city)
    };

    // Graph representation (adjacency list with weights)
    vector<vector<pair<int, int>>> graph(10);
    graph[0].push_back({1, 4}); // Sector 17 to Sector 22, distance 4 km
    graph[0].push_back({2, 2}); // Sector 17 to PGI, distance 2 km
    graph[1].push_back({2, 5}); // Sector 22 to PGI, distance 5 km
    graph[1].push_back({3, 10}); // Sector 22 to Railway Station, distance 10 km
    graph[2].push_back({3, 3}); // PGI to Railway Station, distance 3 km
    graph[3].push_back({4, 11}); // Railway Station to Airport, distance 11 km
    graph[3].push_back({5, 9}); // Railway Station to Sector 35, distance 9 km
    graph[4].push_back({5, 6}); // Airport to Sector 35, distance 6 km
    graph[6].push_back({2, 8}); // Flood-Affected Area to PGI, distance 8 km
    graph[7].push_back({1, 7}); // Earthquake-Affected Area to Sector 22, distance 7 km
    graph[6].push_back({8, 5}); // Flood-Affected Area to Safe Zone A, distance 5 km
    graph[7].push_back({9, 4}); // Earthquake-Affected Area to Safe Zone B, distance 4 km

    // Added edges from every affected area to Safe Zones
    graph[0].push_back({8, 9}); // Sector 17 to Safe Zone A, distance 9 km
    graph[0].push_back({9, 10}); // Sector 17 to Safe Zone B, distance 10 km
    graph[1].push_back({8, 7}); // Sector 22 to Safe Zone A, distance 7 km
    graph[1].push_back({9, 8}); // Sector 22 to Safe Zone B, distance 8 km
    graph[3].push_back({8, 12}); // Railway Station to Safe Zone A, distance 12 km
    graph[3].push_back({9, 15}); // Railway Station to Safe Zone B, distance 15 km
    graph[4].push_back({8, 14}); // Airport to Safe Zone A, distance 14 km
    graph[4].push_back({9, 13}); // Airport to Safe Zone B, distance 13 km
    graph[5].push_back({8, 18}); // Sector 35 to Safe Zone A, distance 18 km
    graph[5].push_back({9, 16}); // Sector 35 to Safe Zone B, distance 16 km
    graph[6].push_back({8, 5}); // Flood-Affected Area to Safe Zone A, distance 5 km
    graph[6].push_back({9, 9}); // Flood-Affected Area to Safe Zone B, distance 9 km
    graph[7].push_back({8, 6}); // Earthquake-Affected Area to Safe Zone A, distance 6 km
    graph[7].push_back({9, 4}); // Earthquake-Affected Area to Safe Zone B, distance 4 km

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
        dijkstra(source, graph, areaNames, safeZoneDetails);
    }

    return 0;
}
