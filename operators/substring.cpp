#include <cstddef>
#include <cstring>
#include <iostream>

using namespace std;

struct String {

    String(const char *str_ = "") {
	    int len = strlen(str_);
	    cout << "str len: " << len << '\n';
	    //We can omit pointer to this here
	    size = len + 1;
	    str = new char[size];
	    strcpy(this->str, str_);
	}
	
	String(size_t n, char c) {
		size = n;
	    this->str = new char[n + 1];
	    for (int i = 0; i < n; i++) {
		    this->str[i] = c;	
	    }	
	}
	
	~String() {
	    delete [] str;
	}
	
	const char *c_str() {
        return str;
    }

    void append(String &str_) {        
        int newSize = size + str_.size;
        char * newString = new char[newSize + 1];
        
        strcpy(newString, str);
        strcpy(newString + size, str_.str);
        
        delete [] str;
        size = newSize;
        str = newString;
    }

    struct Substring {
        
        Substring(const char *str_ = "", size_t start = 0) {	        
	        int len = strlen(str_);
	        size = len + 1;
	        str = new char[size];
	        strcpy(this->str, str_);
	        start_ = start;
	    }
	    
	    ~Substring() {
	        delete [] str;
	    }
        
        String operator[](size_t end) const {
            size_t suffix_size = end - start_;
            char substr[suffix_size + 1];
            for (size_t i = 0; i < suffix_size; ++i) {
                substr[i] = str[i];
            }
            substr[suffix_size] = '\0';
            return String(substr);
        }
        
        size_t size;
	    char *str;
	    size_t start_;
    };
    
    Substring operator[](size_t start) const {
        size_t suffix_size = size - start;
	    char substr[suffix_size];
	    for (size_t i = 0; i < suffix_size; ++i) {
	        substr[i] = str[start + i];
	    }
	    
	    return Substring(substr, start);
    }

    size_t size;
	char *str;

};

int main() {
    char a[] = "hello";
    String s(a);
    String::Substring ss = s[1];
    String s1 = s[1][4];
    cout << s1.c_str() << '\n';
    return 0;
}
