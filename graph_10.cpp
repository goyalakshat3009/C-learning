#include <bits/stdc++.h> // T.C O(V*E)
using namespace std;

class Edge {
public:
    int v;
    int wt;

    Edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    }
};

void bellanFord(int src, vector<vector<Edge>> g, int V) {

    vector<int> dist(V, INT_MAX);

    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {

        for (int u = 0; u < V; u++) {

            for (Edge e : g[u]) {

                if (dist[u] != INT_MAX &&
                    dist[e.v] > dist[u] + e.wt) {

                    dist[e.v] = dist[u] + e.wt;
                }
            }
        }
    }

    // Check for negative weight cycle
    for (int u = 0; u < V; u++) {

        for (Edge e : g[u]) {

            if (dist[u] != INT_MAX &&
                dist[e.v] > dist[u] + e.wt) {

                cout << "Negative weight cycle exists" << endl;
                return;
            }
        }
    }

    // Print shortest distances
    for (int i = 0; i < V; i++) {
        cout << dist[i] << " ";
    }

    cout << endl;
}

int main() {

    int V = 5;
    vector<vector<Edge>> g(V);

    g[0].push_back(Edge(1, 2));
    g[0].push_back(Edge(2, 4));

    g[1].push_back(Edge(4,-1));
    g[1].push_back(Edge(2, -4));

    g[2].push_back(Edge(3, 2));

    g[3].push_back(Edge(4, 4));

    bellanFord(0, g, V);

    return 0;
}