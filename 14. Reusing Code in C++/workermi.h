#ifndef WORKERMI_H_
#define WORKERMI_H_

#include <string>

// An abstract base class
class Worker {
private:
    std::string full_name;
    long id;

protected:
    virtual void Data() const;
    virtual void Get();

public:
    Worker() : full_name("no one"), id(0L) {}
    Worker(const std::string& s, long n) : full_name(s), id(n) {}
    virtual ~Worker() = 0;
    virtual void Set() = 0;
    virtual void Show() const = 0;
};

class Waiter : virtual public Worker {
private:
    int panache;

protected:
    void Data() const;
    void Get();

public:
    Waiter() : Worker(), panache(0) {}
    Waiter(const std::string& s, long n, int p = 0)
        : Worker(s, n), panache(p) {}
    Waiter(const Worker& wk, int p = 0) : Worker(wk), panache(p) {}
    void Set();
    void Show() const;
};

class Singer : virtual public Worker {
protected:
    enum { other, alto, contralto, soprano, bass, baritone, tenor };
    enum { Vtypes = 7 };
    void Data() const;
    void Get();

private:
    static char* pv[Vtypes];
    int voice;

public:
    Singer() : Worker(), voice(other) {}
    Singer(const std::string& s, long n, int v = other)
        : Worker(s, n), voice(v) {}
    Singer(const Worker& wk, int v = other) : Worker(wk), voice(v) {}
    void Set();
    void Show() const;
};

// multiple inheritance
class SingerWaiter : public Waiter, public Singer {
protected:
    void Data() const;
    void Get();

public:
    SingerWaiter() {}
    SingerWaiter(const std::string& s, long n, int p = 0, int v = other)
        : Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {}
    SingerWaiter(const Worker& wk, int p = 0, int v = other)
        : Worker(wk), Waiter(wk, p), Singer(wk, v) {}
    SingerWaiter(const Waiter& wt, int v = other)
        : Worker(wt), Waiter(wt), Singer(wt, v) {}
    SingerWaiter(const Singer& sg, int p = 0)
        : Worker(sg), Waiter(sg, p), Singer(sg) {}
    void Set();
    void Show() const;
};

#endif