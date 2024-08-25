#ifndef ACCTABC_H_
#define ACCTABC_H_
#include <iostream>
#include <string>

// Abstract Base Class
class AcctABC {
private:
    std::string full_name;
    long account_num;
    double balance;

protected:
    struct Formatting {
        std::ios_base::fmtflags flag;
        std::streamsize pr;
    };
    const std::string& FullName() const { return full_name; }
    long AccountNum() const { return account_num; }
    Formatting SetFormat() const;
    void Restore(Formatting& f) const;

public:
    AcctABC(const std::string& s = "Nullbody", long an = -1, double bal = 0.0);
    void Deposit(double amount);
    virtual void Withdraw(double amount) = 0;  // pure virtual function
    double Balance() const { return balance; }
    virtual void ViewAccount() const = 0;  // pure virtual function
    virtual ~AcctABC() {};
};

// Brass Account Class
class Brass : public AcctABC {
public:
    Brass(const std::string& s = "Nullbody", long an = -1, double bal = 0.0)
        : AcctABC(s, an, bal) {}
    virtual void Withdraw(double amount);
    virtual void ViewAccount() const;
    virtual ~Brass() {}
};

// Brass Plus Account Class
class BrassPlus : public AcctABC {
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    BrassPlus(const std::string& s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.1);
    BrassPlus(const Brass& ba, double ml = 500, double r = 0.1);
    virtual void Withdraw(double amount);
    virtual void ViewAccount() const;
    void ResetMax(double m) { maxLoan = m; }
    void ResetRate(double r) { rate = r; }
    void ResetOwes() { owesBank = 0; }
};

#endif