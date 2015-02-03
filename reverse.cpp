#include <iostream>
using namespace std;

void reverse();

main() {
    reverse();
    cout << '\n';
    return 0;
}

void reverse() {
    int a = 0; 
    
    cin >> a;
    
    if (a == 0) {
        return;
    }
    
    reverse();
    cout << a << " ";
}
