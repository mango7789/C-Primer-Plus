#include <iostream>
using std::cout;
using std::endl;

// template prototypes
template <typename T>
void counts();

template <typename T>
void report(T&);

// template class
template <typename T>
class HasFriend {
private:
    T item;
    static int count;

public:
    HasFriend(T i) : item(i) { count++; }
    ~HasFriend() { count--; }
    friend void counts<T>();
    friend void report<>(HasFriend<T>&);
};

template <typename T>
int HasFriend<T>::count = 0;


// template functions
template <typename T>
void counts() {
    cout << "template size: " << sizeof(HasFriend<T>) << "; ";
    cout << "template count: " << HasFriend<T>::count << endl;
}

template <typename T>
void report(T& hf) {
    cout << hf.item << endl;
}

int main() {
    HasFriend<int> i1(10);
    HasFriend<int> i2(20);
    HasFriend<double> d(3.14);

    report(i1);
    report(i2);
    report(d);

    counts<int>();
    counts<double>();       

    return 0;
}