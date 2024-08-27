#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>

int main() {
    using namespace std;
    const int N = 6;
    string s1[N] = { "apple", "banana", "cherry", "date", "elderberry", "fig" };
    string s2[N] = { "cherry", "date", "elderberry", "fig", "grape", "honeydew" };

    set<string> A(s1, s1 + N);
    set<string> B(s2, s2 + N);

    ostream_iterator<string, char> out(cout, " ");

    copy(A.begin(), A.end(), out);
    cout << endl;

    copy(B.begin(), B.end(), out);
    cout << endl;

    set_union(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    set<string> C;
    set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string>>(C, C.begin()));
    copy(C.begin(), C.end(), out);
    cout << endl;

    string s3("date");
    C.insert(s3);
    copy(C.begin(), C.end(), out);
    cout << endl;

    copy(C.lower_bound("banana"), C.upper_bound("date"), out);
    cout << endl;

    return 0;
}