#include <bits/stdc++.h> // all functions T.C. O(1)
using namespace std;

class CircularQueue {
    int* arr;
    int currSize, cap;
    int f = 0, r = -1;

public:
    CircularQueue(int size) {
        cap = size;
        arr = new int[cap];
        currSize = 0;
        f = 0;
        r = -1;
    }

    void push(int data) {
        if (currSize == cap) {
            cout << "Circular Queue is full\n";
            return;
        }

        r = (r + 1) % cap;
        arr[r] = data;
        currSize++;
    }

    void pop() {
        if (empty()) {
            cout << "CQ is empty\n";
            return;
        }

        f = (f + 1) % cap;
        currSize--;
    }

    int front() {
        if (empty()) {
            cout << "CQ is empty\n";
            return -1;
        }

        return arr[f];
    }

    bool empty() {
        return currSize == 0;
    }
};

int main() {
    CircularQueue cq(3);

    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.push(4);

    cout << cq.front() << endl;

    cq.pop();
    cout << cq.front() << endl;

    cq.push(4);
    cout << cq.front() << endl;

    return 0;
}