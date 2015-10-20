#include <iostream>
#include <cstdlib>

using namespace std;

int gcd(int a, int b) {
    if (b > a) {
        return gcd(b, a);
    }
    //We assume that a >= b
    if (b == 0) {
        return a;
    }
    
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    // We assume that both a and b are nonnegative
    return a * b / gcd(a, b);
}

struct Rational
{
    Rational(int numerator = 0, int denominator = 1) : numerator_(numerator), denominator_(denominator) {}
    
    void print() {
        cout << numerator_ << '/' << denominator_ << '\n';    
    }

    void add(Rational rational) {
        int lcm_ = lcm(this->denominator_, rational.denominator_);
        numerator_ = numerator_ * lcm_ / (int) denominator_ + rational.numerator_ * lcm_ / (int) rational.denominator_;
        denominator_ = lcm_;
        
        simplify();
    };
    
    void sub(Rational rational) {
        rational.neg();
        this->add(rational);
    }
    
    void mul(Rational rational) {
        numerator_ *= rational.numerator_;
        denominator_ *= rational.denominator_;
        
        simplify();
    }
    void div(Rational rational) {
        rational.inv();
        this->mul(rational);
    }

    void neg() {
        numerator_ *= -1;
    }
    
    void inv() {
        int den = denominator_;
        
        denominator_ = abs(numerator_);
        numerator_ = numerator_ / abs(numerator_) * den;
    }
    
    double to_double() const {
        return (double) numerator_ / (double) denominator_;
    }
    
    operator double() const {
        return this->to_double();
    }
    
    Rational & operator+=(Rational const& rational) {
        this->add(rational);
        return *this;
    }
    
    Rational & operator-=(Rational const& rational) {
       this->sub(rational);
       return *this; 
    }
    
    Rational & operator*=(Rational const& rational) {
       this->mul(rational);
       return *this; 
    }
    
    Rational & operator/=(Rational const& rational) {
       this->div(rational);
       return *this; 
    }
    
    Rational operator-() const {
        Rational r = Rational(numerator_, denominator_);
        r.neg();
        return r;
    }
    
    Rational operator+() const {
        Rational r = Rational(numerator_, denominator_);
        return r;
    }
    
    int getNumerator() {
        return numerator_;
    }
    
    unsigned getDenominator() {
        return denominator_;
    }

private:
    int numerator_;
    unsigned denominator_;
    
    void simplify() {
        unsigned gcd_ = gcd(numerator_, denominator_);
        
        if (gcd_ > 1) {
            this->numerator_ = numerator_ / gcd_;
            this->denominator_ = denominator_ / gcd_;
        }
    }
};

Rational operator+(Rational r1, Rational const& r2) {
    r1 += r2;
    return r1;
}

Rational operator-(Rational r1, Rational const& r2) {
    r1 -= r2;
    return r1;
}

Rational operator*(Rational r1, Rational const& r2) {
    r1 *= r2;
    return r1;
}

Rational operator/(Rational r1, Rational const& r2) {
    r1 /= r2;
    return r1;
}

bool operator==(Rational const& r1, Rational const& r2) {
    Rational diff = Rational();
    diff += r1 - r2;
    return diff.getNumerator() == 0;
}

bool operator!=(Rational const& r1, Rational const& r2) {
   return !(r1 == r2); 
}

bool operator<(Rational const& r1, Rational const& r2) {
    Rational diff = Rational();
    diff += r1 - r2;
    return diff.getNumerator() < 0;
}

bool operator>(Rational const& r1, Rational const& r2) {
    return r2 < r1;
}

bool operator<=(Rational const& r1, Rational const& r2) {
    return !(r2 < r1);
}
 
bool operator>=(Rational const& r1, Rational const& r2) {
    return !(r1 < r2);
}


int main() {
    Rational a = Rational(1, 2);
    Rational b = Rational(2, 3);
    
    a.add(b);
    a.print();
    
    a.sub(b);
    a.print();
    
    a.mul(a);
    a.print();
    
    a.div(b);
    a.print();
    
    cout << "With operators:\n";
    
    a = Rational(1, 2);
    b = Rational(2, 3); 
    
    a += b;
    a.print();
    
    a -= b;
    a.print();
    
    a *= a;
    a.print();
    
    a /= b;
    a.print();
    
    a += 1;
    a.print();
    
    Rational c = -a;
    c.print();
    
    Rational d = -1;
    d.print();
    
    double db = (double) b;
    cout << db << '\n';

    return 0;
}

