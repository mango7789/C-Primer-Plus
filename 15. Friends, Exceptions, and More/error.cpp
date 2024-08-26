#include <cmath>
#include <iostream>
#include <string>

#include "exc_mean.h"

class Demo {
private:
    std::string name;

public:
    Demo(const std::string& str) : name(str) {
        std::cout << "Demo object created for " << name << std::endl;
    }
    ~Demo() { std::cout << "Demo object destroyed for " << name << std::endl; }
    void show() const {
        std::cout << "Demo object lives for " << name << std::endl;
    }
};

double hmean(double a, double b);
double gmean(double a, double b);
double means(double a, double b);

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    double x, y, z;
    {
        Demo d1("found in block main()");
        cout << "Enter two numbers: ";
        while (cin >> x >> y) {
            try {
                z = means(x, y);
                cout << "The mean of " << x << " and " << y << " is " << z
                     << endl;
                cout << "Enter next two numbers (or just <enter> to quit): ";
            } catch (bad_hmean& bh) {
                bh.message();
                cout << "Try again\n";
                continue;
            } catch (bad_gmean& bg) {
                cout << bg.message();
                cout << "Values used: " << bg.v1 << ", " << bg.v2 << endl;
                cout << "Sorry, you don't get to play any more." << endl;
                break;
            }
        }
        d1.show();
    }

    cout << "Bye.\n";
    cin.get();
    cin.get();
    return 0;
}

double hmean(double a, double b) {
    if (a == -b) throw bad_hmean(a, b);
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) {
    if (a <= 0 || b <= 0) throw bad_gmean(a, b);
    return std::sqrt(a * b);
}

double means(double a, double b) {
    double am, hm, gm;
    Demo d2("found in means()");
    am = (a + b) / 2.0;
    try {
        hm = hmean(a, b);
        gm = gmean(a, b);
    } catch (bad_hmean& bh) {
        bh.message();
        std::cout << "Caught in means()\n";
        throw;
    }
    d2.show();
    return (am + hm + gm) / 3.0;
}
