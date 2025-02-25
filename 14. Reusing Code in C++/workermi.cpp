#include "workermi.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// Worker methods
Worker::~Worker() {}

// protected methods
void Worker::Data() const {
    cout << "Name: " << full_name << endl;
    cout << "Employee ID: " << id << endl;
}

void Worker::Get() {
    getline(cin, full_name);
    cout << "Enter worker's ID: ";
    cin >> id;
    while (cin.get() != '\n') {
        continue;
    }
}

// Waiter methods
void Waiter::Set() {
    cout << "Enter waiter's name: ";
    Worker::Get();
    Get();
}

void Waiter::Show() const {
    cout << "Category: waiter\n";
    Worker::Data();
    Data();
}

void Waiter::Data() const { cout << "Panache rating: " << panache << endl; }

void Waiter::Get() {
    cout << "Enter waiter's panache rating: ";
    cin >> panache;
    while (cin.get() != '\n') {
        continue;
    }
}

// Singer methods
char* Singer::pv[Singer::Vtypes] = {"other", "alto",     "contralto", "soprano",
                                    "bass",  "baritone", "tenor"};

void Singer::Set() {
    cout << "Enter singer's name: ";
    Worker::Get();
    Get();
}

void Singer::Show() const {
    cout << "Category: singer\n";
    Worker::Data();
    Data();
}

void Singer::Data() const { cout << "Vocal range: " << voice << endl; }

void Singer::Get() {
    cout << "Enter number for singer's vocal range:\n";
    int i;
    for (i = 0; i < Vtypes; i++) {
        cout << i << ": " << pv[i] << "  ";
        if (i % 4 == 3) {
            cout << endl;
        }
    }
    if (i % 4 != 0) {
        cout << '\n';
    }
    cin >> voice;
    while (cin.get() != '\n') {
        continue;
    }
}

// SingerWaiter methods
void SingerWaiter::Data() const {
    Waiter::Data();
    Singer::Data();
}

void SingerWaiter::Get() {
    Waiter::Get();
    Singer::Get();
}

void SingerWaiter::Set() {
    cout << "Enter singing waiter's name: ";
    Worker::Get();
    Get();
}

void SingerWaiter::Show() const {
    cout << "Category: singing waiter\n";
    Worker::Data();
    Data();
}