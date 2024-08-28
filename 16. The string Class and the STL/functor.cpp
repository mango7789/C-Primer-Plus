#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>

template <typename T>
class TooBig {
private:
    T cutoff;

public:
    TooBig(const T& cutoff) : cutoff(cutoff) {}
    bool operator()(const T& x) const { return x > cutoff; }
};

void outint(int n) { std::cout << n << " "; }

int main() {
    using std::list;
    using std::cout;
    using std::endl;

    TooBig<int> f100(100);
    
    list<int> ydayda = {50, 100, 90, 180, 60, 120, 415, 88, 201};
    list<int> etcetc {50, 100, 90, 180, 60, 120, 415, 88, 201};

    for_each(ydayda.begin(), ydayda.end(), outint);
    cout << endl;
    for_each(etcetc.begin(), etcetc.end(), outint);
    cout << endl;

    ydayda.remove_if(f100);
    etcetc.remove_if(TooBig<int>(200));

    for_each(ydayda.begin(), ydayda.end(), outint);
    cout << endl;
    for_each(etcetc.begin(), etcetc.end(), outint);
    cout << endl;

    return 0;
}