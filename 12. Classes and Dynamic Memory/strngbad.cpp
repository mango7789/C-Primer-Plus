#include <cstring>
#include "strngbad.h"
using std::cout;

// initialize static class member
int StringBad::num_strings = 0;

// class methods
StringBad::StringBad() {
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");
    num_strings++;
    cout << num_strings << ": \"" << str << "\" default object created\n";
}

StringBad::StringBad(const char* s) {
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
    cout << num_strings << ": \"" << str << "\" object created\n";
}

StringBad::StringBad(const StringBad& st) {
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    num_strings++;
    cout << num_strings << ": \"" << str << "\" object created\n";
}

StringBad::~StringBad() {
    cout << "\"" << str << "\" object deleted, ";
    --num_strings;
    cout << num_strings << " left\n";
    delete[] str;
}

StringBad& StringBad::operator=(const StringBad& st) {
    if (this == &st) return *this;  // object assigned to itself
    delete[] str;   
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

// friend function
std::ostream& operator<<(std::ostream& os, const StringBad& st) {
    os << st.str;
    return os;
}