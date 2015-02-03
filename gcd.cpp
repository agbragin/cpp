#include <iostream>
using namespace std;

int gcd(int, int);

main() {
    int a = 0; 
    int b = 0;
    int out = 0;
    
    cin >> a >> b;
    
    out = gcd(a, b);
    
    cout << out << "\n";
    
    return 0;
}

int gcd(int a, int b) {
    if (b > a) {
        return gcd(b, a);
    }
    //We assume that a >= b
    if (b == 0) {
        return a;
    }
    
    return gcd(b, a % b);
}
