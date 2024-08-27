#include <algorithm>
#include <iostream>
#include <map>
#include <string>

typedef int KeyType;
typedef std::pair<KeyType, std::string> Pair;
typedef std::multimap<KeyType, std::string> MapCode;

int main() {
    using namespace std;
    MapCode codes;

    codes.insert(Pair(1234, "ABC"));
    codes.insert(Pair(9012, "MNO"));
    codes.insert(Pair(1234, "DEF"));
    codes.insert(Pair(5678, "GHI"));
    codes.insert(Pair(5678, "JKL"));
    codes.insert(Pair(9012, "PQR"));

    cout << "Number of pairs with code 1234: " << codes.count(1234) << endl;

    MapCode::iterator it;
    for (it = codes.begin(); it != codes.end(); ++it) {
        cout << it->first << ", " << it->second << endl;
    }

    pair<MapCode::iterator, MapCode::iterator> range = codes.equal_range(5678);
    for (it = range.first; it != range.second; ++it) {
        cout << it->first << ", " << it->second << endl;
    }

    return 0;
}