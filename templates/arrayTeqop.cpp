#include <cstddef>
#include <iostream>

using namespace std;

template <typename T>
class Array
{
public:
    explicit Array(size_t size = 0, const T& value = T()) {
        cout << "T size: " << sizeof(T) << '\n';
        
        size_ = size;
        mem_ = new char[size_ * sizeof(T)];
        values_ = (T*) mem_;
        
        for (size_t i = 0; i < size; ++i) {
            //char * addr = mem_ + (i * sizeof(T));
            //cout << "Addr: " << addr << '\n';
            T * tmp = new (mem_ + i * sizeof(T)) T(value);
            //cout << "Creating object on " << values_ + i * sizeof(T) << " " << tmp << '\n';
        }
        
        for (int i = 0; i < size_; ++i) {
            T * tmp = (T*) (mem_ + i * sizeof(T));
            //cout << tmp->value() << '\n';
        }
        
    }

    Array(Array const & other) {
        size_ = other.size_;
        values_ = (T*) new char[size_ * sizeof(T)];
        
        for (int i = 0; i < size_; ++i) {
            T * tmp = new (mem_ + i * sizeof(T)) T(other.values_[i]);
        }
    }

    ~Array() {
        cout << "Calling Array object destructor. Array size: " << size_ << '\n';
        for (int i = 0; i < size_; ++i) {
            T * object = (T*) (mem_ + i * sizeof(T));
            object->~T();
            
        }
        
        //Free memory
        delete [] mem_;
        mem_ = 0;
        values_ = 0;      
    }

    Array& operator=(Array<T> const & other) {
        if (this != &other) {
            delete [] mem_;
            size_ = other.size_;
            values_ = (T*) new char[size_ * sizeof(T)];
            for (int i = 0; i < size_; ++i) {
                T * tmp = new (mem_ + i * sizeof(T)) T(other.values_[i]);
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
    char * mem_;
    T * values_;
};

struct Test {
    Test(int value) {
        cout << "Creating object with value " << value << '\n';
        value_ = value;
    }
    
    ~Test() {
        cout << "Destroying object with value " << value_ << '\n';
    }
    
    Test(Test const & other) {
        cout << "Call copy constructor for object with value " << other.value_ << '\n';
        value_ = other.value_;
    }
    
    int value() {
        return value_;
    }
    
private:
    Test& operator=(Test const & other);
    
    int value_;
};

int main() {
    /*cout << "Testing with int\n";
    
    Array<int> a(10, 1);
    int value = a[1];
    cout << value << '\n';
    
    for (int i = 0; i < 10; ++i) {
        cout << '\t' << a[i] << '\n';
    }
    
    Array<int> b = a;
    Array<int> c(0, 1);
    c = c;
    Array<int> cc = Array<int>(c);
    Array<int> * aa = new Array<int>(10, 2);
    value = (*aa)[1];
    cout << value << '\n';*/
    
    
    Test t(1);
    cout << "Testing with Test object. Object size: " << sizeof(Test) << "\n";
    
    Array<Test> at(6, t);
    
    /*cout << "Copy array\n";
    
    Array<Test> at1 = at;
    
    at1 = at1;*/

    
    return 0;
}