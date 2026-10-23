// Task 1 - OO analysis: Namma Metro smart-card fare system
#include <iostream>
using namespace std;

enum class Zone { Inner, Middle, Outer };
const int BASE_PAISE[3] = {1000, 2000, 3000};   // Rs 10, 20, 30
const int PEAK_PERCENT = 20;
const long long MIN_BALANCE = 5000;             // Rs 50 must remain

bool isPeak(int h) { return (h >= 8 && h < 10) || (h >= 17 && h < 20); }

// Inheritance + polymorphism: discount depends on passenger type
class Passenger {
public:
    virtual ~Passenger() {}
    virtual int discount() const { return 0; }
};
class Student : public Passenger {
public:
    int discount() const { return 50; }         // assumed 50%
};

// Abstraction: caller only asks for a fare
class FareTable {
public:
    static long long fare(Zone z, int hour, const Passenger& p) {
        long long f = BASE_PAISE[static_cast<int>(z)];
        if (isPeak(hour)) f = f * (100 + PEAK_PERCENT) / 100;
        return f * (100 - p.discount()) / 100;
    }
};

// Encapsulation: balance is private, changed only by deduct()
class SmartCard {
    long long balance;
public:
    SmartCard(long long b) : balance(b) {}
    long long getBalance() const { return balance; }
    bool deduct(long long f) {
        if (balance - f < MIN_BALANCE) return false;
        balance -= f;
        return true;
    }
};

int main()
{
    SmartCard card(10000);                      // Rs 100.00
    Passenger reg;
    Student stu;
    Passenger* p[3] = {&reg, &reg, &stu};
    Zone z[3] = {Zone::Inner, Zone::Outer, Zone::Middle};
    int hour[3] = {12, 9, 12};

    for (int i = 0; i < 3; i++) {
        long long f = FareTable::fare(z[i], hour[i], *p[i]);
        bool ok = card.deduct(f);
        cout << "Fare Rs " << f / 100.0 << (ok ? " OK" : " DENIED")
             << " balance Rs " << card.getBalance() / 100.0 << '\n';
    }
    return 0;
}
