#include <cstddef>
#include <iostream>

using namespace std;

template <typename T>
class Array
{
public:
    explicit Array(size_t size = 0, const T& value = T()) {
        size_ = size;
        values_ = new T[size];
        
        for (size_t i = 0; i < size; ++i) {
            values_[i] = value;
        }
        
    }

    Array(const Array &other) {
        size_ = other.size_;
        values_ = new T[size_];
        
        for (int i = 0; i < size_; ++i) {
            values_[i] = other.values_[i];
        }
    }

    ~Array() {
        delete [] values_;
    }

    Array& operator=(const Array<T> & other) {
        if (this != &other) {
            delete [] values_;
            size_ = other.size_;
            values_ = new T[size_];
            for (int i = 0; i < size_; ++i) {
                values_[i] = other.values_[i];
            }
            return *this;
        }
    }

    size_t size() const {
        return size_;
    }

    T& operator[](size_t index) {
        return values_[index];
    }
    
    const T& operator[](size_t index) const {
        return values_[index];
    }
    
private:
    size_t size_;
    T * values_;
};

int main() {
    Array<int> a(10, 1);
    int value = a[1];
    cout << value << '\n';
    Array<int> b = a;
    Array<int> c(0, 1);
    c = c;
    Array<int> cc = Array<int>(c);
    Array<int> * aa = new Array<int>(10, 2);
    value = (*aa)[1];
    cout << value << '\n';
    return 0;
}
