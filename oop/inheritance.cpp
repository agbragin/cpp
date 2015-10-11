#include <iostream>
using namespace std;

/* Этот код просто напоминание как выглядит класс Foo и функция foo_says.
 * Не нужно его расскоментировать и/или менять.
 *
 */
       
struct Foo {
    void say() const { std::cout << "Foo says: " << msg << "\n"; }
    protected:
    //public:
        Foo(const char *msg) : msg(msg) { }
    private:
    const char *msg;
};
 
struct Bar : Foo {
    public:
        Bar(const char *msg) : Foo(msg) { }
};
 
void foo_says(const Foo &foo) { foo.say(); }

Bar get_foo(const char *msg) {
    return Bar(msg);
}

int main() {
    foo_says(get_foo("Hello!"));
}

