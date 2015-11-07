#include <iostream>
#include <cstddef>

using namespace std;

template <typename U, typename T>
void copy_n(U * to, T * from, size_t n) {
    for (int i = 0; i < n; ++i) {
        to[i] = (U) from[i];
    }
};


int main() {
    int ints[] = {1, 2, 3, 4};
    double doubles[4] = {};
    
    copy_n(doubles, ints, 4);
    
    for (int i = 0; i < 4; ++i) {
        cout << doubles[i] << ' ';
    }
    cout << '\n';
    return 0;
}
