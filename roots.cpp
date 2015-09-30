#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    int a = 0;
    int b = 0;
    int c = 0;
    
    cin >> a >> b >> c;
    
    double sq = b * b - 4 * a * c;
    
    if (sq < 0) {
        cout << "No real roots\n";
    } else {
        double root_1 = (-b + sqrt(sq)) / (2 * a);
        double root_2 = (-b - sqrt(sq)) / (2 * a);
        cout << root_1 << ' ' << root_2 << '\n';
    }

    return 0;
}
