#include "mytime.h"

#include <iostream>

Time::Time() { hours = minutes = 0; }

Time::Time(int h, int m) {
    hours = h;
    minutes = m;
}

void Time::AddMin(int m) {
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h) { hours += h; }

void Time::ReSet(int h, int m) {
    hours = h;
    minutes = m;
}

// Time Time::Sum(const Time& t) const
// {
//     Time sum;
//     sum.minutes = this->minutes + t.minutes;
//     sum.hours = this->hours + t.hours + sum.minutes / 60;
//     sum.minutes %= 60;
//     //! sum is a local variable, the function can't return a reference
//     //! so we return a copy of the sum object
//     return sum;
// }

Time Time::operator+(const Time& t) const {
    Time sum;
    sum.minutes = this->minutes + t.minutes;
    sum.hours = this->hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time Time::operator-(const Time& t) const {
    Time diff;
    int tot1, tot2;
    tot1 = t.minutes + 60 * t.hours;
    tot2 = minutes + 60 * hours;
    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}

Time Time::operator*(double mult) const {
    Time result;
    long totalMinutes = hours * mult * 60 + minutes * mult;
    result.hours = totalMinutes / 60;
    result.minutes = totalMinutes % 60;
    return result;
}

Time operator*(double n, const Time& t) { return t * n; }

std::ostream& operator<<(std::ostream& os, const Time& t) {
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}

void Time::show() const {
    std::cout << hours << " hours, " << minutes << " minutes";
}