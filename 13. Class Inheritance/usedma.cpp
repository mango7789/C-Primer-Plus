#include <iostream>
#include "dma.hpp"

int main() {
    using std::cout;
    using std::endl;

    baseDMA shirt("Portabelly", 8);
    lacksDMA balloon("red", "Blimpo", 4);
    hasDMA map("Mercator", "Keys", 5);

    cout << shirt << endl;
    cout << balloon << endl;
    cout << map << endl;

    lacksDMA balloon2(balloon);
    cout << balloon2 << endl;

    hasDMA map2;
    map2 = map;
    cout << map2 << endl;

    return 0;
}