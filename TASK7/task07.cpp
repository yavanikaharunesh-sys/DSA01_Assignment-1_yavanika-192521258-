// Task 7 - Procedural vs object-oriented
#include <iostream>
using namespace std;

constexpr long long MIN_BALANCE = 5000;            // Rs 50 (change in ONE place)

// ---- Procedural: separate variable + free functions ----
long long pBalance = 10000;
bool pCanTravel(long long f) { return pBalance - f >= MIN_BALANCE; }

// ---- Object-oriented: balance is private ----
class SmartCard {
    long long balance;
public:
    SmartCard(long long b) : balance(b) {}
    bool canTravel(long long f) const { return balance - f >= MIN_BALANCE; }
    bool deduct(long long f) {                     // only way to reduce the balance
        if (!canTravel(f)) return false;
        balance -= f;
        return true;
    }
    long long get() const { return balance; }
};

int main()
{
    long long fares[] = {1000, 3600, 2000};        // Rs 10, 36, 20
    SmartCard card(10000);
    for (long long f : fares) {
        bool p = pCanTravel(f);
        if (p) pBalance -= f;
        bool o = card.deduct(f);
        cout << "Fare Rs " << f / 100 << "  procedural " << (p ? "OK" : "DENIED")
             << " Rs " << pBalance / 100 << "  | OO " << (o ? "OK" : "DENIED")
             << " Rs " << card.get() / 100 << '\n';
    }
    pBalance = -999;                               // any code can break the rule
    cout << "Procedural balance after careless code: " << pBalance << '\n';
    // card.balance = -999;                        // ERROR: balance is private
    return 0;
}
