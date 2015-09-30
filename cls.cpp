#include <iostream>
using namespace std;

struct Cls {
    Cls(char c, double d, int i) : c(c), d(d), i(i) {};
private:
    char c;
    double d;
    int i;
};

// Use this function to get values position
void list(Cls &cls) {
    Cls * obj = &cls;
    char * p_obj = (char *) obj;

    int size = sizeof(cls);
    for (int i = 0; i < size / 4; i++) {
        char * p_i = p_obj + i;
        cout << "byte in object: " << i << " value: " << * p_i << '\n';
    }
}

char &get_c(Cls &cls) {
    
    Cls * obj = &cls;
    char * p_obj = (char *) obj;
    
    char & r_c = * p_obj;
    return r_c;
}

double &get_d(Cls &cls) {
    
    Cls * obj = &cls;
    double * p_obj = (double *) obj;
    double * p_d = p_obj + 1;
    
    double & r_d = * p_d;
    return r_d;
}

int &get_i(Cls &cls) {
    
    Cls * obj = &cls;
    int * p_obj = (int *) obj;
    int * p_i = p_obj + 4;
    
    int & r_i = * p_i;
    return r_i;
}

int main() {
    Cls a('x', 3.14, 759);
    
    cout << "sizes: " << sizeof('x') << ' ' << sizeof(3.14) << ' ' << sizeof(1) << " struct: " << sizeof(a) << '\n';
    
    char r_c = get_c(a);
    cout << r_c << '\n';
    
    char & c_value = get_c(a);
    cout << "c value: " <<  c_value << '\n';
    
    int & i_value = get_i(a);
    cout << "i value: " <<  i_value << '\n';
    
    double & d_value = get_d(a);
    cout << "d value: " <<  d_value << '\n';
    
    list(a);
}
