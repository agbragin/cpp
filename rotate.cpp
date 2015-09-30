#include <iostream>
using namespace std;

/**
    Rotate array using array indexes
*/
void rotate(int a[], unsigned size, int shift)
{
    int copy[size];
    
    for (int i = 0; i < size; i++) {
        copy[i] = a[i];
    }
    
    for (int i = 0; i < size; i++) {
        a[i] = copy[(i + shift) % size];
    }
}

/**
    Rotate array using pointers
*/
void rotate_p(int a[], unsigned size, int shift)
{
    int copy[size];
    int * a_p = a;
    int * copy_p = copy;
    
    for (copy_p = copy; copy_p < copy + size; copy_p++) {
        * copy_p = * a_p;
        a_p++;
    }
    
    copy_p = copy;
    for (a_p = a; a_p < a + size; a_p++) {
        * a_p = * (copy_p + ((a_p - a) + shift) % size);
    }
}

int main() {

    int a[] = {1, 2, 3, 4, 5};
    rotate_p(a, 5, 2);
    
    for (int i = 0; i < 5; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}
