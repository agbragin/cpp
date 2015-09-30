#include <iostream>
using namespace std;

int main() {
    int numbers = 0;
    cin >> numbers;
    
    for (int i = 0; i < numbers; i++) {
        int a = 0;
        int b = 0;
        cin >> a >> b;
        cout << a + b << '\n'; 
    }
    
    return 0;
}
