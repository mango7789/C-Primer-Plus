#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
const long Size1 = 39L;
const long Size2 = 100 * Size1;
const long Size3 = 100 * Size2;

bool f3(int x) { return x % 3 == 0; }
bool f13(int x) { return x % 13 == 0; }

int main() {
    using std::cout;
    using std::endl;
    std::srand(std::time(0));

    // using function pointers
    std::vector<int> numbers(Size1);
    std::generate(numbers.begin(), numbers.end(), std::rand);
    int count3 = std::count_if(numbers.begin(), numbers.end(), f3);
    int count13 = std::count_if(numbers.begin(), numbers.end(), f13);
    cout << count3 << ", " << count13 << endl;

    // using a functor
    numbers.resize(Size2);
    std::generate(numbers.begin(), numbers.end(), std::rand);
    class f_mod {
    private:
        int dv;

    public:
        f_mod(int d = 1) : dv(d) {}
        bool operator()(int x) { return x % dv == 0; }
    };
    count3 = std::count_if(numbers.begin(), numbers.end(), f_mod(3));
    count13 = std::count_if(numbers.begin(), numbers.end(), f_mod(13));
    cout << count3 << ", " << count13 << endl;

    // using lambdas
    numbers.resize(Size3);
    std::generate(numbers.begin(), numbers.end(), std::rand);
    count3 = std::count_if(numbers.begin(), numbers.end(), [](int x) { return x % 3 == 0; });
    count13 = std::count_if(numbers.begin(), numbers.end(), [](int x) { return x % 13 == 0; });
    cout << count3 << ", " << count13 << endl;

    return 0;
}