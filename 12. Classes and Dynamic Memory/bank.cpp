#include <cstdlib>
#include <ctime>
#include <iostream>

#include "queue.h"
const int MIN_PER_HR = 60;

bool new_customer(double x);

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;

    // setting things up
    std::srand(time(0));
    cout << "Case study: Bank of Heather Automatic Teller\n";

    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs);

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cycle_limit = MIN_PER_HR * hours;

    cout << "Enter the average number of customers per hour: ";
    double per_hour;
    cin >> per_hour;
    double min_per_customer;
    min_per_customer = MIN_PER_HR / per_hour;  // interval for each customer

    Item temp;
    long turn_away = 0;  // turned away by full queue
    long customers = 0;  // joined the queue
    long served = 0;     // served during the simulation
    long sum_line = 0;   // cumulative line length
    int wait_time = 0;   // time until teller is free
    long line_wait = 0;  // cumulative time in line

    // running the simulation
    for (int cycle = 0; cycle < cycle_limit; cycle++) {
        if (new_customer(min_per_customer)) {
            if (line.isfull()) {
                turn_away++;
            } else {
                customers++;
                temp.set(cycle);
                line.enqueue(temp);
            }
        }

        if (wait_time <= 0 && !line.isempty()) {
            line.dequeue(temp);
            wait_time = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }

        if (wait_time > 0) {
            wait_time--;
        }

        sum_line += line.queuecount();
    }

    // report results
    if (customers > 0) {
        cout << "Customers accepted: " << customers << endl;
        cout << "Customers Served  : " << served << endl;
        cout << "Turn away         : " << turn_away << endl;
        cout << "Average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cycle_limit << endl;
        cout << "Average wait time : "
             << (double) line_wait / served << " minutes\n";
    } else {
        cout << "No Customers!\n";
    }
    cout << "Done!\n";

    return 0;
}

bool new_customer(double x) { return std::rand() * x / RAND_MAX < 1; }