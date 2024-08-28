#include <algorithm>
#include <iostream>
#include <valarray>
#include <vector>

int main() {
    using namespace std;
    vector<double> data;
    double temp;

    cout << "Enter data (press q to stop): ";
    while (cin >> temp) {
        data.push_back(temp);
    }
    sort(data.begin(), data.end());

    int size = data.size();
    valarray<double> numbers(size);
    for (int i = 0; i < size; i++) {
        numbers[i] = data[i];
    }

    valarray<double> sqrts = sqrt(numbers);
    valarray<double> results = numbers + 2 * sqrts;

    cout.setf(ios_base::fixed);
    cout.precision(4);
    for (int i = 0; i < size; i++) {
        cout.width(8);
        cout << numbers[i] << ": ";
        cout.width(8);
        cout << results[i] << endl;
    }

    cout << "Done.\n";

    return 0;
}