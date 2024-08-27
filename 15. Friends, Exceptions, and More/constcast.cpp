#include <iostream>
using std::cout;
using std::endl;

void change(const int *p, int n);   

int main() {
    int pop1 = 28383;
    const int pop2 = 2000;  //! pop2 is originally const, so const_cast will not work here
    cout << "pop1, pop2: " << pop1 << ", " << pop2 << endl;

    change(&pop1, -103);
    change(&pop2, -103);

    cout << "pop1, pop2: " << pop1 << ", " << pop2 << endl;

    return 0;
}

void change(const int *p, int n) {
    //! const_cast can only be used with pointers or references
    int *q = const_cast<int *>(p);
    *q += n;
}