#include <cstring>
#include "string.h"
using std::cin;
using std::cout;

// initialize static class member
int String::num_strings = 0;

// static method
int String::HowMany() { return num_strings; }

// class methods
String::String() {
    len = 0;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const char* s) {
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
}

String::String(const String& st) {
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    num_strings++;
}

String::~String() {
    num_strings--;
    delete[] str;
}

// overloaded operator methods
String& String::operator=(const char* s) {
    delete[] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

String& String::operator=(const String& st) {
    if (this == &st) return *this;
    delete[] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

char& String::operator[](int i) { return str[i]; }

const char& String::operator[](int i) const { return str[i]; }

// overloaded operator friends
bool operator<(const String& st1, const String& st2) {
    return std::strcmp(st1.str, st2.str) < 0;
}

bool operator>(const String& st1, const String& st2) {
    return st2 < st1;
}

bool operator==(const String& st1, const String& st2) {
    return std::strcmp(st1.str, st2.str) == 0;
}

ostream& operator<<(ostream& os, const String& st) {
    os << st.str;
    return os;
}

istream& operator>>(istream& is, String& st) {
    char temp[String::CLINLIM];
    is.get(temp, String::CLINLIM);
    if (is) {
        st = temp;
    }
    while (is && is.get() != '\n') {
        continue;
    }
    return is;
}

