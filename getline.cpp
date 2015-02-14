#include <iostream>
using namespace std;

void myswap(int *, int *);
char * getline();

main() {
    char * a = getline();
    for (char * i = a ; *i != '\0'; i++) {
        cout << *i;
    }
    cout << endl;
    delete [] a;
    a = 0;
}

char *getline() {
    int size = 4;
    char * a = new char[size];
    
    int i = 0;
    char c;
    while (cin.get(c) && c != '\n') {
        if (i == size) {
            //Reallocate array
            size *= 2;
            char * new_array = new char[size];
            for (int j = 0; j < size / 2; j++) {
                new_array[j] = a[j];
            }
            delete [] a;
            a = new_array;
        }
        
        a[i] = c;
        i++;
    }
    a[i] = '\0';
    return a;
}

