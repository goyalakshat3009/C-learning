#include <bits/stdc++.h>
using namespace std;

class DisJointSetUnion {
public:
    int n;
    vector<int> par,rank;

    DisJointSetUnion(int n) {
        this->n = n;
        for(int i=0; i<n; i++) {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    void unionByBank(int a,int b) {
        int parA=find(a);
        int parB=find(b);

        if(parA==parB) return;
        if(rank[parA]==rank[parB]) { // case 1
            par[parB]=parA;
            rank[parA]++;
        }
        else if(rank[parA]>rank[parB]) { // case 2
            par[parB]=parA;
        }
        else { // case 3
            par[parA]=parB;
        }
    }

    int find(int x) {
        if(par[x]==x) return x;
        return find(par[x]);
    }

    void getInfo() {
        for(int i=0; i<n; i++) {
            cout << par[i] << " ";
        }
        cout << endl;

        for(int i=0; i<n; i++) {
            cout << rank[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DisJointSetUnion dsu(6);

    dsu.unionByBank(0,2);
    cout << dsu.find(2) << endl;

    dsu.unionByBank(1,3);
    dsu.unionByBank(2,5);
    dsu.unionByBank(0,3);
    cout << dsu.find(2) << endl;

    dsu.unionByBank(0,4);

    dsu.getInfo();
    return 0;
}