#include <cstddef>
#include <cstring>
#include <iostream>

using namespace std;



/*struct Prefix : String {
    
    Prefix(const char *str_ = "") {
	    int len = strlen(str_);
	    //We can omit pointer to this here
	    size = len;
	    str = new char[len];
	    strcpy(this->str, str_);
	}
    
    Prefix operator[](size_t end) const {
        
        size_t suffix_size = size - end;
        cout << suffix_size << '\n';
        char * substr = new char[suffix_size];
        for (size_t i = 0; i < suffix_size; ++i) {
            substr[i] = str[i];
        }
        
        return Prefix(substr);
    }
    
    size_t size;
	char *str;

};*/
/*struct String {
	String(const char *str = "");
	String(size_t n, char c);
	~String();

	void append(const String &other);
	const char *c_str();
	
	Prefix operator[](size_t start);

	size_t size;
	char *str;
};*/



struct String {
	
	String(const char *str_ = "") {
	    int len = strlen(str_);
	    //We can omit pointer to this here
	    size = len;
	    str = new char[len];
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

	size_t size;
	char *str;
	
	/**
	    Get substring of specified string.
	    
	    start - zero-based substring start
	    end - zero-based substring end (exclusive) 
	*/
	String operator[](size_t start) const {
        size_t suffix_size = size - start;
        cout << suffix_size << '\n';
	    char * substr = new char[suffix_size];
	    for (size_t i = 0; i < suffix_size; ++i) {
	        substr[i] = str[start + i];
	    }
	    
	    String prefix = String(substr);
	    
	    return prefix;
	}
};



//};

 
int main() {
    char a[] = "abcdefg";
    String s(a);
    cout << s.c_str() << '\n';
    size_t start = 2;
    String ss = s[4][5];
    cout << ss.c_str() << '\n';
    
}
