#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(E log V)
int primMST(int V, vector<vector<pair<int, int>>> adj) {

    vector<bool> inMST(V, false);

    // Min Heap -> {weight, vertex}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    int mstCost = 0;

    pq.push({0, 0}); // {weight, vertex}

    while (!pq.empty()) {

        auto p = pq.top();
        pq.pop();

        int wt = p.first;
        int u = p.second;

        // If vertex is already included, skip it
        if (inMST[u])
            continue;

        // Include vertex in MST
        inMST[u] = true;
        mstCost += wt;

        // Check all neighbours
        for (auto edge : adj[u]) {

            int v = edge.first;
            int weight = edge.second;

            // If v is not already in MST
            if (!inMST[v]) {
                pq.push({weight, v});
            }
        }
    }

    return mstCost;
}

int main() {

    int V = 4;

    vector<vector<pair<int, int>>> adj(V);

    // Undirected weighted graph
    // {vertex, weight}

    adj[0].push_back({1, 10});
    adj[1].push_back({0, 10});

    adj[0].push_back({3, 30});
    adj[3].push_back({0, 30});

    adj[0].push_back({2, 15});
    adj[2].push_back({0, 15});

    adj[1].push_back({3, 40});
    adj[3].push_back({1, 40});

    adj[2].push_back({3, 50});
    adj[3].push_back({2, 50});

    cout << "Minimum cost of MST = "
         << primMST(V, adj) << endl;

    return 0;
}