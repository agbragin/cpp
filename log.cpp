#include <iostream>
using namespace std;

int log2(int);

int main()  {
    int num = 0;
    
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        int x = 0;
        cin >> x;
        cout << log2(x) << '\n';
    }
    
    return 0;
}

int log2(int x) {
    int pow = 1;
    int log2 = 0;
    
    while (pow <= x / 2) {
        pow *= 2;
        log2++;
    }
    
    return log2;
}
