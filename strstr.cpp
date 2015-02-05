#include <iostream>
using namespace std;

int strstr(const char *str, const char *pattern);

main() {

    const char string[] = "Hello, world!\0";
    const char pattern[] = "ello\0";
    
    int pos = strstr(string, pattern);
    
    cout << pos << endl;
}

int strstr(const char *str, const char *pattern) {
    if (*pattern == '\0') {
        return 0;
    }
    
    for (int pos = 0; *(str + pos) != '\0'; pos++) {
        //Set pointer to the beginng of the pattern
        int i = 0;
        while (*(str + pos + i) != '\0') {
            //If we reached pattern end then pattern is in string in the position specified
            if (*(pattern + i) == '\0') {
                return pos;
            }
            //If symbols do not match then stop search at position pos
            if (*(str + pos + i) != *(pattern + i)) {
                break;
            }
            i++;
        }
        //To do "H/0" "H/0" case properly
        if (*(pattern + i) == '\0') {
            return pos;
        }
    }
    
    return -1;
}

