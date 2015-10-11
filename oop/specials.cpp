
struct IInterface {
    virtual void something() = 0;
    virtual ~IInterface() {};
};

struct Base {
    virtual void run() = 0;
    virtual ~Base() {}
protected:
    virtual void do_protected() {}
private:
    virtual void do_private() {}
};

struct Children : private Base {
public:
    void do_protected() { Base::do_protected(); }
    void do_private() {}
    
    void do_somehing() {
        Base::do_protected();
        // Compillation fault
        //Base::do_private();
    }
    
private:
    void run() {}
};

int main() {
    return 0;
}
