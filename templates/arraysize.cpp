#include <iostream>
#include <cstddef> // size_t

template<typename T, size_t size>
int array_size(T (&nums)[size]) {
    return size;
}

int main() {
    int ints[] = {1, 2, 3, 4};
    int *iptr = ints;
    double doubles[] = {3.14};
    std::cout << array_size(ints) << '\n'; // returns 4
    std::cout << array_size(doubles) << '\n'; // returns 1
    //std::cout << array_size(iptr) << '\n'; // compilation error
}
