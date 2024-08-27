#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>

void outint(int n) { std::cout << n << " "; }

int main() {
    using namespace std;

    list<int> one(5, 2);
    int staff[5] = {1, 2, 4, 8, 16};
    list<int> two;
    two.insert(two.begin(), staff, staff + 5);
    int more[6] = {6, 4, 2, 4, 6, 5};
    list<int> three(two);
    three.insert(three.end(), more, more + 6);

    cout << "one: ";
    for_each(one.begin(), one.end(), outint);
    cout << endl;

    cout << "two: ";
    for_each(two.begin(), two.end(), outint);
    cout << endl;

    cout << "three: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl;

    three.remove(2);
    cout << "three after remove(2): ";
    for_each(three.begin(), three.end(), outint);
    cout << endl;

    //! splice moves the original range into the destination
    three.splice(three.begin(), one);
    cout << "three after splice(one): ";
    for_each(three.begin(), three.end(), outint);
    for_each(one.begin(), one.end(), outint);
    cout << endl;

    three.unique();
    cout << "three after unique(): ";
    for_each(three.begin(), three.end(), outint);
    cout << endl;

    three.sort();
    three.unique();
    cout << "three after sort() and unique(): ";
    for_each(three.begin(), three.end(), outint);
    cout << endl;

    two.sort();
    three.merge(two);
    cout << "three after merge(two): ";
    for_each(three.begin(), three.end(), outint);
    cout << endl;

    return 0;
}