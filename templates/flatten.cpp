#include <iostream>


// Весь вывод должен осущствляться в поток out,
// переданный в качестве параметра.
//
// Можно заводить любые вспомогаетльные функции,
// структуры или даже изменять сигнатуру flatten,
// но при этом все примеры вызова из задания должны
// компилироваться и работать.

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

template <typename T>
void flatten(const Array< Array<T> >& array, std::ostream& out) { 
    for (int i = 0; i < array.size(); ++i) {
        flatten(array[i], out);
    }
}

template <typename T>
void flatten(const Array<T>& array, std::ostream& out) { 
    for (int i = 0; i < array.size(); ++i) {
        out << array[i] << ' ';
    }
}


int main() {
    return 0;
}
