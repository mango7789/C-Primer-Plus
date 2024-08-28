#include <iostream>
#include <utility>

// interface
class UseLess {
private:
    int n;
    char* pc;
    static int count;
    void ShowObject() const;

public:
    UseLess();
    explicit UseLess(int k);
    UseLess(int k, char ch);
    UseLess(const UseLess& f);  // regular copy constructor
    UseLess(UseLess&& f);       // move constructor
    ~UseLess();
    UseLess operator+(const UseLess& f) const;
    UseLess& operator=(const UseLess& f);  // copy assignment
    UseLess& operator=(UseLess&& f);       // move assignment
    void ShowData() const;
};

// implementation
int UseLess::count = 0;

UseLess::UseLess() {
    ++count;
    n = 0;
    pc = nullptr;
}

UseLess::UseLess(int k) : n(k) {
    ++count;
    pc = new char[n];
}

UseLess::UseLess(int k, char ch) : n(k) {
    ++count;
    pc = new char[n];
    for (int i = 0; i < n; i++) {
        pc[i] = ch;
    }
}

UseLess::UseLess(const UseLess& f) : n(f.n) {
    ++count;
    pc = new char[n];
    for (int i = 0; i < n; i++) {
        pc[i] = f.pc[i];
    }
}

UseLess::UseLess(UseLess&& f) : n(f.n) {
    ++count;
    pc = f.pc;       // steal address
    f.pc = nullptr;  // give old object nothing in return
    f.n = 0;
}

UseLess::~UseLess() { delete[] pc; }

UseLess UseLess::operator+(const UseLess& f) const {
    UseLess temp(n + f.n);
    for (int i = 0; i < n; i++) {
        temp.pc[i] = pc[i];
    }
    for (int i = n; i < temp.n; i++) {
        temp.pc[i] = f.pc[i - n];
    }
    return temp;
}

UseLess& UseLess::operator=(const UseLess& f) {
    std::cout << "copy assignment operator called:\n";
    if (this == &f) {
        return *this;
    }
    delete[] pc;
    n = f.n;
    pc = new char[n];
    for (int i = 0; i < n; i++) {
        pc[i] = f.pc[i];
    }
    return *this;
}

UseLess& UseLess::operator=(UseLess&& f) {
    std::cout << "move assignment operator called:\n";
    if (this == &f) {
        return *this;
    }
    delete[] pc;
    n = f.n;
    pc = f.pc;
    f.n = 0;
    f.pc = nullptr;
    return *this;
}

void UseLess::ShowObject() const {
    std::cout << "Number of elements: " << n;
    std::cout << " Data address: " << (void*)pc << std::endl;
}

void UseLess::ShowData() const {
    if (n == 0) {
        std::cout << "(object empty)";
    } else {
        for (int i = 0; i < n; i++) {
            std::cout << pc[i];
        }
    }
    std::cout << std::endl;
}

int main() {
    using std::cout;
    using std::endl;

    {
        UseLess one(10, 'x');
        UseLess two = one + one;
        cout << "Object one: ";
        one.ShowData();
        cout << "Object two: ";
        two.ShowData();

        UseLess three, four;
        three = one;
        three.ShowData();
        one.ShowData();

        four = one + two;
        four.ShowData();

        four = std::move(one);
        four.ShowData();
        one.ShowData();
    }

    return 0;
}
