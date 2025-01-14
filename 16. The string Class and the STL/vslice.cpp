#include <cstdlib>
#include <iostream>
#include <valarray>

const int SIZE = 12;
typedef std::valarray<int> vint;
void show(const vint& v, int cols);

int main() {
    using std::cout;
    using std::slice;
    vint valint(SIZE);  // think of as 4 rows of 3

    for (int i = 0; i < SIZE; i++) {
        valint[i] = std::rand() % 10;
    }
    show(valint, 3);

    vint vcol(valint[slice(1, 4, 3)]);
    show(vcol, 1);

    vint vrow(valint[slice(3, 3, 1)]);
    show(vrow, 3);

    valint[slice(2, 4, 3)] = 10;
    show(valint, 3);

    //! + not defined for slices, so convert to valarry<int>
    valint[slice(0, 4, 3)] =
        vint(valint[slice(1, 4, 3)]) + vint(valint[slice(2, 4, 3)]);
    show(valint, 3);

    return 0;
}

void show(const vint& v, int cols) {
    using std::cout;
    using std::endl;

    int lim = v.size();
    for (int i = 0; i < lim; i++) {
        cout.width(3);
        cout << v[i];
        if (i % cols == cols - 1)
            cout << endl;
        else
            cout << ' ';
    }
    cout << endl;
}