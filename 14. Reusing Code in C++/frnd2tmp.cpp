#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class HasFriend {
private:
    T item;
    static int count;

public:
    HasFriend(T i) : item(i) { count++; }
    ~HasFriend() { count--; }
    friend void counts();
    friend void reports(HasFriend<T>&);
};

template <typename T>
int HasFriend<T>::count = 0;

void counts() {
    cout << "int count: " << HasFriend<int>::count << "; ";
    cout << "double count: " << HasFriend<double>::count << endl;
}

void reports(HasFriend<int>& hfi) {
    cout << "HasFriend<int>: " << hfi.item << endl;
}

void reports(HasFriend<double>& hfd) {
    cout << "HasFriend<double>: " << hfd.item << endl;
}

int main() {
    cout << "No objects created yet: ";
    counts();

    HasFriend<int> hf1(42);
    cout << "After creating hfi1: ";
    counts();

    HasFriend<int> hf2(100);
    cout << "After creating hfi2: ";
    counts();

    HasFriend<double> hfd(3.14);
    cout << "After creating one double object: ";
    counts();

    reports(hf1);
    reports(hf2);
    reports(hfd);

    return 0;
}