#include <iostream>
#include <vector>
using namespace std;

void printSubsets(vector<int> &arr, vector<int> &ans, int i) { //T.C.(2^n * n)
    if (i == arr.size()) {
        for (int val : ans) {
            cout << val << " ";
        }
        cout << endl;
        return;
    }

    // Include current element
    ans.push_back(arr[i]);
    printSubsets(arr, ans, i + 1);

    // Exclude current element
    ans.pop_back();
    printSubsets(arr, ans, i + 1);
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    vector<int> ans;   // stores current subset

    printSubsets(arr, ans, 0);

    return 0;
}
