#include <iostream>
using namespace std;

int strlen(const char string[]) {
    
    int len = 0;
    while (true) {
        if (string[len] == '\0') {
            break;
        }
        len++;
    }
    
    return len;
}

main() {
    char tmp[] = "Hello\0";
    int len = strlen(tmp);
    cout << len << endl;
}
