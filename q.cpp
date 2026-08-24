#include <iostream>
using namespace std;

int main() {
    int n = 6;
    int arr[6] = {4, 6, 7, 3, 8, 9};

    for (int st = 0; st < n; st++) {
        for (int end = st; end < n; end++) {
            for (int i = st; i <= end; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
