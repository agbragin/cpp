#include <iostream>

using namespace std;

struct Expression
{
    virtual double evaluate() const = 0;
    virtual ~Expression() {};
};

struct Number : Expression
{
    Number(double value) : value(value) {};
    ~Number() {
        cout << "Deleting number instance\n";
    }
    
    double evaluate() const { return value; }
    double get_value() const { return value; }

private:
    double value;
};

struct BinaryOperation : Expression
{
    BinaryOperation(Expression const * left, char op, Expression const * right) 
            : left(left), op(op), right(right) {};
    
    ~BinaryOperation() {
        delete left;
        delete right;
    }
    
    double evaluate() const {
        if (op == '+') {
            return left->evaluate() + right->evaluate();
        } else if (op == '-') {
            return left->evaluate() - right->evaluate();
        } else if (op == '*') {
            return left->evaluate() * right->evaluate();
        } else if (op == '/') {
            return left->evaluate() / right->evaluate();
        }
    }

    Expression const * get_left() const { return left; }
    Expression const * get_right() const { return right; }
    char get_op() const { return op; }

private:
    Expression const * left;
    Expression const * right;
    char op;
};

struct RefCount {
    RefCount() : counter(1) {}
    int counter;
};

struct SharedPtr
{
    explicit SharedPtr(Expression *ptr = 0) {
        ptr_ = ptr;
        
        if (ptr_ != 0) {
            ref_count_ = new RefCount();
        } else {
            ref_count_ = 0;
        }
    }
    
    ~SharedPtr() {
        if (ptr_ != 0) {
            this->decrementAndDestroy();
        }
    }
    
    void decrementAndDestroy() {
        ref_count_->counter--;
        if (ref_count_->counter == 0) {
            delete ptr_;
            delete ref_count_;
            ptr_ = 0;
            ref_count_ = 0;
        }
    }
    
    SharedPtr(const SharedPtr& sharedPtr) {
        ptr_ = sharedPtr.ptr_;
        
        if (ptr_ != 0) {
            ref_count_ = sharedPtr.ref_count_;
            ref_count_->counter++;
        } else {
            ref_count_ = 0;
        }
    }
    
    SharedPtr& operator=(const SharedPtr& sharedPtr) {
        if (this != &sharedPtr) {

            if (ptr_ != 0) {
                this->decrementAndDestroy();
            }
            
            if (sharedPtr.ptr_ != 0) {
                sharedPtr.ref_count_->counter++;
            }
            
            ptr_ = sharedPtr.ptr_;
            ref_count_ = sharedPtr.ref_count_;
        }
        
        return *this;
    }
    
    Expression* get() const {
        return ptr_;
    }
    
    void reset(Expression *ptr = 0) {
        if (ptr_ != 0) {
            this->decrementAndDestroy();
        }
        ptr_ = ptr;
        if (ptr_ != 0) {
            ref_count_ = new RefCount();
        } else {
            ref_count_ = 0;
        }
    }
    
    Expression& operator*() const {
        return *ptr_;
    }
    
    Expression* operator->() const {
        return ptr_;
    }
    
    int count() {
        return ref_count_->counter;
    }
    
private:
    Expression* ptr_;
    RefCount* ref_count_;
    
    SharedPtr(Expression* ptr, RefCount* ref_count) : ptr_(ptr), ref_count_(ref_count) {} 
};

int main() {
    Expression * n = new Number(0.0);
    Expression * n1 = new Number(1.0);
    Expression * n2 = new Number(2.0);
    cout << n->evaluate() << '\n';
    cout << "Entering block\n";
    {
        SharedPtr spn(0);
        
        SharedPtr sp(n);
        
        cout << "References to " << n << " : " << sp.count() << '\n';
        
        cout << "Get pointer...\n";
        Expression * e = sp.get();
        cout << "Pointers: " << n << " " << e << '\n';
        
        {
            SharedPtr sp1 = sp;
            sp1 = sp1;
            cout << "References to " << n << " : " << sp.count() << '\n';
            Expression * e = sp1.get();
            cout << "Pointers: " << n << " " << e << '\n';
            
            cout << "Exiting inner block\n";
        }
       
        cout << "References to " << n << " : " << sp.count() << '\n';
        cout << "Exiting block\n";
    }
    cout << "Exited block\n";
    
    return 0;
}
