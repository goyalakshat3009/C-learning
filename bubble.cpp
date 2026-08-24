#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int A[],int N) {
    for(int i=0; i<N-1; i++) {
        for(int j=0; j<N-i-1; j++) {
            if(A[j]>A[j+1]) {
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
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
    BubbleSort(A,N);
    print(A,N);
    return 0;
}