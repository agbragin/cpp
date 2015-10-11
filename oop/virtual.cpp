#include <iostream>
using namespace std;

struct Expression
{
    double virtual evaluate() const = 0;
    virtual ~Expression() {};
};

struct Number : Expression
{
    Number(double value)
        : value(value)
    {}

private:
    double value;
    
public:
    double evaluate() const {
        return value;
    }
    
    ~Number() {}
};

struct BinaryOperation : Expression
{
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
    BinaryOperation(Expression const * left, char op, Expression const * right)
        : left(left), op(op), right(right)
    {}

private:
    Expression const * left;
    Expression const * right;
    char op;
    

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
    
    ~BinaryOperation() {
        delete left;
        delete right;
    }
};

int main() {
    Expression * a = new Number(7);
    Expression * b = new Number(3);
    Expression * apb = new BinaryOperation(a, '+', b);
    
    cout << apb->evaluate() << '\n';
    
}
