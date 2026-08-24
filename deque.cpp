#include <bits/stdc++.h>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);

    dq.push_back(4);
    // cout << dq.front() << " " << dq.back() << endl;
    dq.pop_back(); // 4,1,2
    cout << dq.front() << " " << dq.back() << endl;
    return 0;
}