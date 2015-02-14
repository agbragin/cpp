#include <iostream>
using namespace std;

int strlen(const char[]);

int strlen(const char[] inp) {
    
    int len = 0;
    while (true) {
        if (inp[len] == '\0') {
            break;
        }
        len++;
    }
    
    return len;
}

main() {
    char inp[] = "C-style string";
    cout << strlen(inp) << endl;
}


