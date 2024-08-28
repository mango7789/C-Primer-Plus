#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

void Show(double);
const int LIM = 6;

int main() {
    using namespace std;

    double arr1[LIM] = {1.2, 3.4, 5.6, 7.8, 9.0, 11.2};
    double arr2[LIM] = {2.3, 4.5, 6.7, 8.9, 10.1, 12.3};

    vector<double> v1(arr1, arr1 + LIM);
    vector<double> v2(arr2, arr2 + LIM);

    cout.setf(ios_base::fixed);
    cout.precision(2);

    cout << "v1:\t";
    for_each(v1.begin(), v1.end(), Show);
    cout << endl;

    cout << "v2:\t";
    for_each(v2.begin(), v2.end(), Show);
    cout << endl;

    vector<double> sum(LIM);
    transform(v1.begin(), v1.end(), v2.begin(), sum.begin(), plus<double>());
    cout << "sum:\t";
    for_each(sum.begin(), sum.end(), Show);
    cout << endl;

    vector<double> prod(LIM);
    transform(v1.begin(), v1.end(), prod.begin(), bind(multiplies<double>(), placeholders::_1, 2.5));
    cout << "prod:\t";
    for_each(prod.begin(), prod.end(), Show);
    cout << endl;

    return 0;
}

void Show(double x) {
    std::cout.width(6);
    std::cout << x << ' ';
}