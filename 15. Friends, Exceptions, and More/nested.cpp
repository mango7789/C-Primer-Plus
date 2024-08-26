#include <iostream>
#include <string>

#include "queuetp.h"

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    Queue<string> cs(5);
    string name;

    while (!cs.isFull()) {
        cout << "Enter name: ";
        getline(cin, name);
        cs.enqueue(name);
    }

    cout << "Queue is full. Processing begins!\n";

    while (!cs.isEmpty()) {
        cs.dequeue(name);
        cout << "Now processing " << name << endl;
    }

    return 0;
}