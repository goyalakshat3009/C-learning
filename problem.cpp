#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	
	while(T--) {
	    int N;
	    cin >> N;
	    
	    int A[N], B[N];
	    for(int i=0; i<N; i++) {
	    cin >> A[i];
	    cin >> B[i];
	    }
	    bool possible = true;
	    for(int i=0; i<N-1; i++) {
	        if((A[i] < A[i+1]) != (B[i] < B[i+1])) {
	            possible = false;
	            break;
	        }
	    }
	    if (possible)
	    cout << "YES\n";
	    else
	    cout << "NO\n";
	}
	return 0;
}
