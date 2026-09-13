#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int>* l;

public:
    // Constructor
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    // Add Edge
    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    // Print Graph
    void printGraph() {
        for (int i = 0; i < V; i++) {

            cout << i << " -> ";

            for (int neighbour : l[i]) {
                cout << neighbour << " ";
            }

            cout << endl;
        }
    }

    // Destructor
    ~Graph() {
        delete[] l;
    }
};


int main() {

    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.printGraph();

    return 0;
}