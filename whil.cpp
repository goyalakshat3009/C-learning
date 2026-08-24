#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long binary;
    cout << "Enter a binary number: ";
    cin >> binary;

    int decimal = 0, i = 0;
    while (binary != 0) {
        int digit = binary % 10;     // take last digit
        decimal += digit * pow(2, i); // add digit × 2^position
        binary /= 10;                // remove last digit
        i++;
    }

    cout << "Decimal number: " << decimal << endl;
    return 0;
}
