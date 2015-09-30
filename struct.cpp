#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

struct Line {
    Point a;
    Point b;
};

int main() {
    Point a = {1, 2};
    Point b = {2, 1};
    Line ab = {a, b};
    
    Point * p_a = &a;
    Point * p_b = &b;
    Line * p_ab = &ab;
    
    cout << p_a << '\n' << p_b << '\n';
    
    cout << a.x << ' ' << a.y << '\n';
    
    a.x = 7;
    p_a->y = 7;
    
    cout << a.x << ' ' << a.y << '\n';
    
    
    Point p_la = p_ab->a;
    
    cout << p_la.x << '\n';
    
}
