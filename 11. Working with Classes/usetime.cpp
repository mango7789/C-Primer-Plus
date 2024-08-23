#include "mytime.h"

int main() {
    using std::cout;
    using std::endl;

    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;
    Time diff;
    Time adjusted;

    cout << "planning time = ";
    planning.show();
    cout << endl;

    cout << "coding time = ";
    coding.show();
    cout << endl;

    cout << "fixing time = ";
    fixing.show();
    cout << endl;

    total = coding + fixing;
    cout << "coding + fixing = ";
    total.show();
    cout << endl;

    diff = fixing - coding;
    cout << "fixing - coding = ";
    diff.show();
    cout << endl;

    adjusted = total * 1.5;
    cout << "total * 1.5 = ";
    adjusted.show();
    cout << endl;

    adjusted = 1.5 * total;
    cout << "1.5 * total = ";
    cout << adjusted;
    cout << endl;

    return 0;
}