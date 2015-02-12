#include <iostream>
using namespace std;

void swap_min(int **mt, int m, int n);

main() {

    int r = 3;
    int c = 4;
    int ** m = new int * [r];
    m[0] = new int[c]{1, 2, 3, 4};
    m[1] = new int[c]{5, 6, 7, 8};
    m[2] = new int[c]{9, 10, 11, 12};
    
    swap_min(m, r, c);
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
}

void swap_min(int **mt, int m, int n) {
    int min = mt[0][0];
    int minRow = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mt[i][j] < min) {
                min = mt[i][j];
                minRow = i;                
            }
        }
    }
    int * swap = mt[0];
    mt[0] = mt[minRow];
    mt[minRow] = swap;
    swap = 0;
}

