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

    explicit ValueHolder(const T& data) {
        data_ = &data;
        //cout << "Data address: " << data_ << '\n';
    }
    
    ~ValueHolder() {
        //cout << "Deleting data on " << data_ << '\n';
        delete data_;
    }
    
    ValueHolder* clone() const {
        //cout << "Cloning data on " << data_ << '\n';
        T& dataCopy = * new T(*data_);
        ValueHolder * clone = new ValueHolder(dataCopy);
        return clone;
    }

    T const * data_;
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

int main() {
    Test &t = *new Test(1);
    //Test t1 = t;
    ValueHolder<Test> * vh = new ValueHolder<Test>(t);
    ValueHolder<Test> * vh1 = vh->clone();
    delete vh;
    delete vh1;
}
