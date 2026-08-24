#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "No. of element is:\n";
    cin >> n;
    
    int arr[n];

    for(int i = 0; i < n; i++) {
        cout << i + 1 << " element is: ";
        cin >> arr[i];
    }
    for(int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
    }

    cout << "Sorted Array is:\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
