#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
const long size = 390000L;

int main() {
    using std::cout;
    using std::endl;

    std::srand(std::time(0));
    std::vector<int> numbers(size);
    std::generate(numbers.begin(), numbers.end(), std::rand);

    // using lambdas
    int count3 = std::count_if(numbers.begin(), numbers.end(), [](int x) { return x % 3 == 0; });
    int count13 = 0;
    std::for_each(numbers.begin(), numbers.end(), [&count13](int x){count13 += x % 13 == 0;});
    cout << count3 << ", " << count13 << endl;

    // using single lambda
    count3 = count13 = 0;
    std::for_each(numbers.begin(), numbers.end(), [&](int x){count3 += x % 3 == 0; count13 += x % 13 == 0;});
    cout << count3 << ", " << count13 << endl;

    return 0;
}