#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<int> v;

public:
    void push(int val) { // O(1)
        v.push_back(val);
    }

    void pop() { // O(1)
        v.pop_back();
    }

    int top() { // O(1)
        return v[v.size()-1];
    }

    bool empty() {
        return v.size()==0;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}