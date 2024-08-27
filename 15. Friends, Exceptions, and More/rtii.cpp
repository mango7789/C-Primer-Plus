#include <cstdlib>
#include <iostream>
#include <random>
#include <typeinfo>
using namespace std;

class Grand {
private:
    int hold;

public:
    Grand(int h = 0) : hold(h) {}
    virtual void Speak() const { cout << "I'm a grand class." << endl; }
    virtual int Value() const { return hold; }
};

class Superb : public Grand {
public:
    Superb(int h = 0) : Grand(h) {}
    void Speak() const { cout << "I'm a superb class." << endl; }
    virtual void Say() const {
        cout << "I hold the superb value of " << Value() << endl;
    }
};

class Magnificent : public Superb {
private:
    char ch;

public:
    Magnificent(int h = 0, char c = 'a') : Superb(h), ch(c) {}
    void Speak() const { cout << "I'm a magnificent class." << endl; }
    void Say() const {
        cout << "I hold the magnificent value of " << Value()
             << " and my char is " << ch << endl;
    }
};

Grand* GetOne();
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dis(0, 999);

int main() {
    Grand* pg;
    Superb* ps;
    for (int i = 0; i < 5; i++) {
        pg = GetOne();
        cout << "Now processing type: " << typeid(*pg).name() << endl;
        pg->Speak();
        if ((ps = dynamic_cast<Superb*>(pg))) ps->Say();
        if (typeid(*pg) == typeid(Magnificent))
            cout << "Yes, you're really magnificent!\n";
    }

    return 0;
}

Grand* GetOne() {
    Grand* p;

    switch (dis(gen) % 3) {
        case 0:
            p = new Grand(dis(gen) % 100);
            break;
        case 1:
            p = new Superb(dis(gen) % 100);
            break;
        case 2:
            p = new Magnificent(dis(gen) % 100, 'a' + dis(gen) % 26);
            break;
    }

    return p;
}