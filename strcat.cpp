#include <iostream>
using namespace std;

void strcat(char *to, const char *from);

main() {
    char a[17] = "Hi\0";
    const char b[] = " W\0";
    
    strcat(a, b);
    
    for (int i = 0; i < 14; i++) {
        cout << a[i];
    }
    
    cout << endl;
    
    return 0;
}

void strcat(char *to, const char *from) {
    while (*to != '\0') {        
        ++to;
    }
    while (*from != '\0') {
        * to++ = * from++;
    }
    * to = '\0';
}
