#include <cstring> // strlen, strcpy
#include <iostream>
using namespace std;

struct String {

    /* Constructors */
    String(const char *str = "") {
        int len = strlen(str);
	    //We can omit pointer to this here
	    this->size_ = len;
	    this->str_ = new char[len];
	    strcpy(this->str_, str);
    }

    String(size_t n, char c) {
	    this->size_ = n;
	    this->str_ = new char[n + 1];
	    for (int i = 0; i < n; i++) {
		    this->str_[i] = c;	
	    }	
    }

    /* Destructor */
    ~String() {
        delete [] str_;
    }

    /* Fields */
    size_t size_;
    char *str_;
    
    /* Methods */
    size_t size() {
        return size_;
    }
    
    char &at(size_t idx) {
        return str_[idx];
    }
    
    const char *c_str() {
        return str_;
    }
    
    int compare(String &str) {
        return strcmp(this->str_, str.str_);
    }
};

main() {
	char a[] = "Hello!";
	char b[] = "World";
	String s(a);
	String s1(b);
	cout << s.size() << endl;
	cout << s.at(1) << endl;
	cout << s.c_str() << endl;
	cout << s.compare(s1) << endl;
}


