#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    vector<int> arr = {6,8,0,1,3};

    stack<int> s;
    vector<int> ans(arr.size());

    for(int i = arr.size()-1; i >= 0; i--) { // T.C O(N), S.C O(N)
        while(!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        if(s.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = s.top();
        }

        s.push(arr[i]);
    }

    // print
    for(int val : ans) {
        cout << val << " ";
    }

    return 0;
}