#include <iostream>
#include "tabtenn.hpp"

int main(void) {
    using std::cout;
    using std::endl;

    TableTennisPlayer player1("Tara", "Boomdea", false);
    RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
    
    rplayer1.Name();
    if (rplayer1.HasTable()) {
        cout << ": has a table.\n";
    } else {
        cout << ": hasn't a table.\n";
    }

    player1.Name();
    if (player1.HasTable()) {
        cout << ": has a table.\n";
    } else {
        cout << ": hasn't a table.\n";
    }

    cout << "Name: ";
    rplayer1.Name();
    cout << "; Rating: " << rplayer1.Rating() << endl;

    //! You can use both the base class and derived class
    // RatedPlayer rplayer2(1212, player1);
    RatedPlayer rplayer2(1212, rplayer1);
    cout << "Name: ";
    rplayer2.Name();
    cout << "; Rating: " << rplayer2.Rating() << endl;

    return 0;
}