#ifndef MYTIME_H_
#define MYTIME_H_
#include <iostream>

class Time {
private:
    int hours;
    int minutes;

public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void ReSet(int h = 0, int m = 0);
    Time operator+(const Time& t) const;
    Time operator-(const Time& t) const;
    Time operator*(double n) const;
    friend Time operator*(double n, const Time& t);
    friend std::ostream& operator<<(std::ostream& os, const Time& t);
    void show() const;
};

#endif