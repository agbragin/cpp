#include <iostream>
using namespace std;

class String {

    String(const char *str = "");
	String(size_t n, char c);
	~String();


    /* Реализуйте конструктор копирования */
	String(const String &other) : size(other.size), str(new char[size + 1]){
	    for (int i = 0; i <= size; i++) {
	        str[i] = other.str[i];
	    }
	}
	
	String &operator=(const String &other) {
	    if (this != &other) {
	        delete [] str;
	        size = other.size;
	        str = new char[other.size];
	        for (int i = 0; i <= size; i++) {
	            str[i] = other.str[i];
	        }
	        return *this;
	    }
	}


	void append(const String &other);

	size_t size;
	char *str;

}

