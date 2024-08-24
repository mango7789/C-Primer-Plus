#ifndef STRING_H_
#define STRING_H_
#include <iostream>
using std::istream;
using std::ostream;

class String {
private:
    char* str;
    int len;
    static int num_strings;
    static const int CLINLIM = 80;
public:
    // constructors and other methods
    String();
    String(const char* s);
    String(const String&);
    ~String();
    int length() const { return len; }
    // overloaded operator methods
    String& operator=(const char*);
    String& operator=(const String&);
    char& operator[](int i);
    const char& operator[](int i) const;
    // overloaded operator friends
    friend bool operator<(const String& st1, const String& st2);
    friend bool operator>(const String& st1, const String& st2);
    friend bool operator==(const String& st1, const String& st2);
    friend ostream& operator<<(ostream& os, const String& st);
    friend istream& operator>>(istream& is, String& st);
    // static function
    static int HowMany();
};

#endif