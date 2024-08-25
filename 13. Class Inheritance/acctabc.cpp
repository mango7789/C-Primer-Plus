#include "acctabc.hpp"

#include <iostream>
using std::cout;
using std::endl;
using std::ios_base;
using std::string;

// Abstract Base Class
AcctABC::AcctABC(const string& s, long an, double bal) {
    full_name = s;
    account_num = an;
    balance = bal;
}

void AcctABC::Deposit(double amount) {
    if (amount < 0) {
        cout << "Negative deposit not allowed; deposit is cancelled.\n";
    } else {
        balance += amount;
    }
}

void AcctABC::Withdraw(double amount) { balance -= amount; }

AcctABC::Formatting AcctABC::SetFormat() const {
    Formatting f;
    f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}

void AcctABC::Restore(Formatting& f) const {
    cout.setf(f.flag, ios_base::floatfield);
    cout.precision(f.pr);
}

// Brass Methods
void Brass::Withdraw(double amount) {
    if (amount < 0) {
        cout << "Negative withdraw not allowed; withdraw is cancelled.\n";
    } else if (amount <= Balance()) {
        AcctABC::Withdraw(amount);
    } else {
        cout << "Withdraw amount of $" << amount << " exceeds your balance.\n";
    }
}

void Brass::ViewAccount() const {
    Formatting f = SetFormat();
    cout << "Brass Client: " << FullName() << endl;
    cout << "Account Number: " << AccountNum() << endl;
    cout << "Balance: " << Balance() << endl;
    Restore(f);
}

// BrassPlus methods
BrassPlus::BrassPlus(const string& s, long an, double bal, double ml, double r)
    : AcctABC(s, an, bal) {
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}

BrassPlus::BrassPlus(const Brass& ba, double ml, double r) : AcctABC(ba) {
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}

void BrassPlus::Withdraw(double amount) {
    Formatting f = SetFormat();

    double balance = Balance();
    if (amount < balance) {
        AcctABC::Withdraw(amount);
    } else if (amount <= balance + maxLoan - owesBank) {
        double advance = amount - balance;
        owesBank += advance * (1 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        AcctABC::Withdraw(amount);
    } else {
        cout << "Credit limit exceeded. Transaction cancelled.\n";
    }
    Restore(f);
}

void BrassPlus::ViewAccount() const {
    Formatting f = SetFormat();

    cout << "Brass Client: " << FullName() << endl;
    cout << "Account Number: " << AccountNum() << endl;
    cout << "Balance: " << Balance() << endl;

    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout.precision(3);
    cout << "Loan Rate: " << 100 * rate << endl;
    Restore(f);
}
