#include <cstddef>
#include <iostream>


template <typename T>
class Array
{
public:
	explicit Array(size_t size = 0, const T& value = T());
	Array(const Array& other);
	~Array();
	Array& operator=(Array other);
	void swap(Array &other);
	size_t size() const;
	T& operator[](size_t idx);
	const T& operator[](size_t idx) const;

private:
	size_t size_;
	T *data_;
};

template <typename T, typename C>
T minimum(const Array<T> & array, C comparator) {
    T minimum = array[0];
    for (int i = 0; i < array.size(); ++i) {
        if (!comparator(minimum, array[i])) {
           minimum = array[i]; 
        }
    }
    return minimum;
}

// Objects for testing
bool less(int a, int b) { return a < b; }
struct Greater { bool operator()(int a, int b) const { return b < a; } };

int main() {
    // Code for testing (requires Array class implementation)
    /*Array<int> ints(3);
    ints[0] = 10;
    ints[1] = 2;
    ints[2] = 15;
    int min = minimum(ints, less); // 2
    std::cout << min << '\n';
    int max = minimum(ints, Greater()); // 15
    std::cout << max << '\n';*/
}
