#ifndef STRNGBAD_H_
#define STRNGBAD_H_
#include <iostream>

class StringBad {
private:
    char* str;
    int len;
    static int num_strings;

public:
    StringBad();
    StringBad(const char* s);
    StringBad(const StringBad& st);
    ~StringBad();

    StringBad& operator=(const StringBad& st);
    // friend function
    friend std::ostream& operator<<(std::ostream& os, const StringBad& st);
};

#endif