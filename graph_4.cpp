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

    bool isCycleUndirDFS(int src, int par, vector<int>& vis) {

        vis[src] = 1;

        for (int v : l[src]) {

            // If neighbour is not visited
            if (!vis[v]) {

                if (isCycleUndirDFS(v, src, vis)) {
                    return true;
                }
            }

            // If neighbour is visited and is NOT parent
            else if (v != par) {
                return true;
            }
        }

        return false;
    }

    bool isCycle() {

        vector<int> vis(V, 0);

        // For disconnected graph
        for (int i = 0; i < V; i++) {

            if (!vis[i]) {

                if (isCycleUndirDFS(i, -1, vis)) {
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