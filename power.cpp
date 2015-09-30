#include <iostream>
using namespace std;

int power(int, unsigned);

int main(int argc, char ** argv) {
    cout << power(2, 0) << '\n';
}

int power(int x, unsigned p) {
    int answer;
    answer = 1;
    for (int i = 0; i < p; i++) {
        answer *= x;
    }
    return answer;
}


