#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 9999
using namespace std;

class dijkstra {
public:
    int dist[100];
    int path[100];
    int visited[100];
    int v;
    int src;

    void read(int cost[50][50]);
    void initialize(int cost[50][50]);
    void perform(int cost[50][50]);
    void display();
};

void dijkstra::initialize(int cost[50][50]) {
    for (int i = 0; i < v; i++) {
        path[i] = src;
        dist[i] = cost[src][i];
        visited[i] = 0;
    }
    visited[src] = 1;

}

void dijkstra::read(int cost[50][50]) {
    cout << "Enter the cost matrix (use " << MAX << " for no connection):" << endl;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cin >> cost[i][j];
        }
    }
}

void dijkstra::perform(int cost[50][50]) {
    for (int count = 1; count < v; count++) {

        int u = -1;
        int minDist = MAX;

        for (int i = 0; i < v; i++) {
            if (!visited[i] && dist[i] < minDist) {
                u = i;
                minDist = dist[i];
            }
        }


        if (u == -1) break;

        visited[u] = 1;


        for (int i = 0; i < v; i++) {
            if (!visited[i] && cost[u][i] != MAX) {

                dist[i] = min(dist[i], dist[u] + cost[u][i]);
                if (dist[i] == dist[u] + cost[u][i]) {
                    path[i] = u;
                }
            }
        }
    }
}

void dijkstra::display() {
    int dest;
    cout << "Enter the destination vertex: ";
    cin >> dest;



    cout << "The shortest path from vertex " << src << " to vertex " << dest << " is:" << endl;
    for (int i=0;i<v;i++)
    {
        cout <<dist[i]<<""<<path[i]<<endl;

    }

    vector<int> spath;
    int curr = dest;
    while (curr != src) {
        spath.push_back(curr);
        curr = path[curr];
    }
    spath.push_back(src);

    for (int i = spath.size() - 1; i >= 0; i--) {
        cout << spath[i];
        if (i != 0) cout << " -> ";
    }
    cout << endl;

    cout << "Total cost: " << dist[dest] << endl;
}

int main() {
    int cost[50][50];
    dijkstra d;

    cout << "Enter the number of vertices: ";
    cin >> d.v;

    d.read(cost);

    cout << "Enter the source vertex: ";
    cin >> d.src;



    d.initialize(cost);
    d.perform(cost);

    d.display();

    return 0;
}
