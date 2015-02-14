#include <iostream>
using namespace std;

main() {
    int a, b;
    int out = 0;
    
    cin >> a >> b;
    
    for (int i = a; i < b; i++) {
        if ((i % 4 == 0 && i % 100 != 0) 
            || i % 400 == 0) {
            out++;
        }
    }
    
    cout << out << "\n";

    return 0;
}
