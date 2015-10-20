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

struct ScopedPtr
{
    // реализуйте следующие методы:
    explicit ScopedPtr(Expression *ptr = 0) {
        ptr_ = ptr;
    }
    
    ~ScopedPtr() {
        delete ptr_;
    }
    
    Expression* get() const {
        return ptr_;
    }
    
    Expression* release() {
        Expression* ptrtmp = ptr_;
        ptr_ = 0;
        return ptrtmp;
    }
    
    void reset(Expression *ptr = 0) {
        delete ptr_;
        ptr_ = ptr;
    }
    
    Expression& operator*() const {
        return *ptr_;
    }
    
    Expression* operator->() const {
        return ptr_;
    }


private:
    // запрещаем копирование ScopedPtr
    ScopedPtr(const ScopedPtr&);
    ScopedPtr& operator=(const ScopedPtr&);

    Expression *ptr_;
};

int main() {
    Expression * n = new Number(0.0);
    Expression * n1 = new Number(1.0);
    Expression * n2 = new Number(2.0);
    cout << n->evaluate() << '\n';
    cout << "Entering block\n";
    {
        ScopedPtr sp(n);
        
        cout << "Get pointer...\n";
        Expression * e = sp.get();
        cout << "Pointers: " << n << " " << e << '\n';
        
        cout << "Release pointer...\n";
        e = sp.release();
        cout << "Pointers: " << n << " " << e << '\n';
        
        cout << "Get after release...\n";
        e = sp.get();
        cout << "Pointers: " << n << " " << e << '\n';
        
        ScopedPtr sp1(n1);        
        cout << "Reset pointer...\n";
        sp1.reset(n2);
        cout << "Pointers: " << n2 << " " << sp1.get() << '\n';
        
        Expression& eop = * sp1;
        cout << "Evaluate: " << eop.evaluate() << '\n';
        
        cout << "Exiting block\n";
    }
    cout << "Exited block\n";
    
    // Cause segmentation fault cause object is already deleted
    //cout << n->evaluate() << '\n';
    return 0;
}
