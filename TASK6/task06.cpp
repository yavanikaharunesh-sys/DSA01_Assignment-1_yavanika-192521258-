// Task 6 - Control structures (Complete the Code)
#include <iomanip>
#include <iostream>

enum class Zone { Inner, Middle, Outer };

constexpr int BASE_PAISE[] = {1000, 2000, 3000};   // Rs 10, Rs 20, Rs 30
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;      // Rs 50 must remain on the card

long long fare(Zone z, bool peak)
{
    long long base;
    switch (z) {                                   // TODO 1
        case Zone::Inner:  base = BASE_PAISE[0]; break;
        case Zone::Middle: base = BASE_PAISE[1]; break;
        case Zone::Outer:  base = BASE_PAISE[2]; break;
        default:           base = 0;             // no case matches
    }
    if (peak) base += base * PEAK_SURCHARGE_PERCENT / 100;   // integer arithmetic only
    return base;
}

bool canTravel(long long balance, long long f)
{
    return balance - f >= MIN_BALANCE_PAISE;       // TODO 2
}

bool isPeak(int hour)                              // 10:00 and 20:00 are NOT peak
{
    return (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
}

int main()
{
    long long balance = 10000;                     // Rs 100.00 in paise
    struct Trip { Zone zone; bool peak; };
    Trip trips[] = {{Zone::Inner, false}, {Zone::Outer, true}, {Zone::Middle, false}};
    for (const Trip& t : trips) {
        long long f = fare(t.zone, t.peak);
        if (canTravel(balance, f)) {
            balance -= f;
            std::cout << "Fare Rs " << f / 100 << '.' << std::setw(2)
                      << std::setfill('0') << f % 100 << std::setfill(' ');
        } else {
            std::cout << "Denied (low balance)";
        }
        std::cout << "  balance Rs " << balance / 100 << '\n';
    }

    // Boundary check: exactly 10 AM and exactly 8 PM
    std::cout << "10:00 peak? " << std::boolalpha << isPeak(10)
              << " | 20:00 peak? " << isPeak(20) << '\n';
}
