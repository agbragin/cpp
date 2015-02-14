#include <iostream>
using namespace std;

int main() {
    char c = '\0';
    bool beginning = true;
    bool blanks = false;
    while (cin >> noskipws >> c) {
        if (c != ' ') {                        
            if (blanks == true) {
                if (!beginning) {
                    cout << ' ';
                }
                blanks = false;
            }
            beginning = false;
            cout << c;                       
        } else {
            blanks = true;        
        }
    }
    return 0;
}
