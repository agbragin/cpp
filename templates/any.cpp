#include <iostream>
#include "valueholder.cpp"

class Any {

public:
    
    Any() : value_(0) {}

    template <typename T>
    explicit Any(T value) {
        value_ = new ValueHolder<T>(value);
    }

    ~Any() {
        delete value_;
    }

    Any(const Any & other) {
        if (other.value_) { 
            value_ = other.value_->clone();
        } else {
            value_ = 0;
        }        
    }

    Any & operator=(const Any & other) {
        if (this != &other) {
            delete value_;
            if (other.value_) {
                value_ = other.value_->clone();
            } else {
                value_=  0;
            }
            return *this;
        }
    }
    
    template <typename T>
    Any & operator=(T value) {
        delete value_;
        value_ = new ValueHolder<T>(value);
    }
    
    template <typename T>
    T * cast() {
        ValueHolder<T> * valueHolder = dynamic_cast<ValueHolder<T> *>(value_);
        if (valueHolder) {
            return &valueHolder->data_;
        } else {
            return 0;
        }
    }
    
private:
    ICloneable * value_;
};

int main() {
    
    Any empty;        
    cout << empty.cast<int>() << '\n';
    Any i(10);
    int * iv = i.cast<int>();
    cout << * i.cast<int>() << '\n';
    cout << i.cast<double>() << '\n';
    Any j = i;
    cout << * j.cast<int>() << '\n';
    Any copy(i);
    cout << * copy.cast<int>() << '\n';
    empty = copy;
    cout << * empty.cast<int>() << '\n';
    empty = 0;
    cout << * empty.cast<int>() << '\n';
    
    Any empty1;
    Any copy1 = empty1;
}
