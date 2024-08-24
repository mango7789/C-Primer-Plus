#include <iostream>
#include "strngbad.h"
using std::cout;

void callme1(StringBad&);
void callme2(StringBad);

int main() {
    using std::endl;
    {
        cout << "Starting an inner block.\n";

        StringBad headline1("Celery Stalks at Midnight");
        StringBad headline2("Lettuce Prey");
        StringBad sports("Spinach Leaves Bowl for Dollars");
        cout << "headlines1: " << headline1 << endl;
        cout << "headlines2: " << headline2 << endl;
        cout << "sports: " << sports << endl;

        callme1(headline1);
        cout << "headlines1: " << headline1 << endl;
        callme2(headline2);
        cout << "headlines2: " << headline2 << endl;

        cout << "Initialize one object to another:\n";
        StringBad sailor = sports;  //! This calls copy constructor
        cout << "sailor: " << sailor << endl;

        cout << "Assign one object to another:\n";
        StringBad knot;
        knot = headline1;           //! This calls assignment operator
        cout << "knot: " << knot << endl;

        cout << "Exiting the block.\n";
    }
    cout << "End of main()\n";

    return 0;
}

void callme1(StringBad& rsb) {
    cout << "String passed by reference:\n";
    cout << "    \"" << rsb << "\"\n";
}

void callme2(StringBad sb) {
    cout << "String passed by value:\n";
    cout << "    \"" << sb << "\"\n";
}