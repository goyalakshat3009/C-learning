#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int>* l;

public:

    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool isCycleUndirBFS(int src, vector<int>& vis) {

        queue<pair<int, int>> q;

        // {node, parent}
        q.push({src, -1});
        vis[src] = 1;

        while (!q.empty()) {

            int u = q.front().first;
            int parU = q.front().second;

            q.pop();

            for (int v : l[u]) {

                // If not visited
                if (!vis[v]) {

                    vis[v] = 1;

                    // v is node, u is its parent
                    q.push({v, u});
                }

                // Already visited and not parent
                else if (v != parU) {
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle() {

        vector<int> vis(V, 0);

        // Handles disconnected graph
        for (int i = 0; i < V; i++) {

            if (!vis[i]) {

                if (isCycleUndirBFS(i, vis)) {
                    return true;
                }
            }
        }

        return false;
    }
};


int main() {

    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    cout << g.isCycle() << endl;

    return 0;
}