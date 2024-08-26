#include <iostream>

class bad_hmean {
private:
    double v1;
    double v2;

public:
    bad_hmean(double a, double b) : v1(a), v2(b) {}
    void message() const;
};

inline void bad_hmean::message() const {
    std::cout << "hmean(" << v1 << ", " << v2 << "): "
              << "invalid arguments: a = -b\n";
}

class bad_gmean {
public:
    double v1;
    double v2;
    bad_gmean(double a, double b) : v1(a), v2(b) {}
    const char* message() const;
};

inline const char* bad_gmean::message() const {
    return "gmean() arguments must be positive\n";
}