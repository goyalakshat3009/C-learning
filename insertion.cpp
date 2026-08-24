#include <bits/stdc++.h>
using namespace std;

void insertionSort(int A[],int N) {
    for (int i=1; i<N; i++) {
        int key=A[i];
        int j=i-1;

        while(j>=0 && A[j]>key) {
            A[j+1] =A[j];
            j--;
        }
        A[j+1]=key;
    }
}
void print(int A[],int N) {
    for (int i=0; i<N; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main() {
    int N;
    cin >> N;

    int A[N];
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }
    insertionSort(A,N);
    print(A,N);
    return 0;
}