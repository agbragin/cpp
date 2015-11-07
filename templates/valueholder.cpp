#include <cstddef>
#include <iostream>

using namespace std;

struct ICloneable
{
	virtual ICloneable* clone() const = 0;
	virtual ~ICloneable() { }
};

template <typename T>
struct ValueHolder : ICloneable {

    explicit ValueHolder(const T& data) : data_(data) {}
    
    ~ValueHolder() {}
    
    ValueHolder* clone() const {
        return new ValueHolder(data_);
    }

    T data_;
};

struct Test {
    explicit Test(int value) {
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

/*
int main() {
    int const v = 10;
    int const * pv = &v;
    ValueHolder<int> vh(v);
    cout << vh.data_ << '\n';
    ValueHolder<int> * clone = vh.clone();
    cout << (*clone).data_ << '\n';
    
    Test t(1);
    Test t1 = t;
    ValueHolder<Test> vh1(t);
    cout << vh1.data_.value() << '\n';
    ValueHolder<Test> * vh2 = vh1.clone();
    cout << vh2->data_.value() << '\n';
}
*/
