#include <iostream>
#include <cstddef>  // size_t
using namespace std;

int ** transpose(const int * const * m, size_t r, size_t c);

main() {
/*
    size_t r = 3;
    size_t c = 4;
    const int ** const m = new const int * [r];
    m[0] = new const int[c]{1, 2, 3, 4};
    m[1] = new const int[c]{5, 6, 7, 8};
    m[2] = new const int[c]{9, 10, 11, 12};
    
    int ** n = transpose(m, r, c);*/
    
    size_t r = 0;
    size_t c = 0;
    const int ** const m = new const int * [r];
    m[0] = new const int[c]{};
    
    int ** n = transpose(m, r, c);
    
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cout << n[i][j] << " ";
        }
        cout << endl;
    }
}

int ** transpose(const int * const * m, size_t r, size_t c) {
    
    int ** n = new int * [c];
    int * data = new int[r * c];
    
    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            data[j * c + i] = m[i][j];
        }
        n[j] = data + j * c; 
    }
    
    return n;
}
