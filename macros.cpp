#include <iostream>
using namespace std;

#define MAX(x, y, r) {int xa = (x); int xb = (y); r = xa > xb ? xa : xb; };

int main() {
    int r = 0;
    
    MAX(4, 5, r);
    cout << r << '\n';
    MAX(5, 1, r);
    cout << r << '\n';
    MAX(2 + 3, 1 + 1, r);
    cout << r << '\n';
    int test = 4;
    MAX(++test, 1 + 1, r);
    cout << r << '\n';
    test = 4;
    MAX(test++, 1 + 1, r);
    cout << r << '\n';
}
