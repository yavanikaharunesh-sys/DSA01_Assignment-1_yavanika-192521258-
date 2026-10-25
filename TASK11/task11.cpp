// Task 11 - Final design: constexpr table + enum class + SmartCard (long long paise)
#include <chrono>
#include <iostream>
using namespace std;

enum class Zone { Inner, Middle, Outer };
constexpr long long BASE_PAISE[] = {1000, 2000, 3000};   // fare revision = edit this line only
constexpr int PEAK_PERCENT = 20;
constexpr long long MIN_BALANCE = 5000;

long long fare(Zone z, int hour)
{
    long long f = BASE_PAISE[static_cast<int>(z)];
    bool peak = (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
    return peak ? f + f * PEAK_PERCENT / 100 : f;
}

class SmartCard {
    long long balance;
public:
    explicit SmartCard(long long b) : balance(b) {}
    bool deduct(long long f) { if (balance - f < MIN_BALANCE) return false; balance -= f; return true; }
    long long get() const { return balance; }
};

int main()
{
    const int N = 3000000;                              // whole network, one day
    SmartCard card(10000000000LL);                      // big card so the loop runs fully
    long long collected = 0; int denied = 0;
    auto t1 = chrono::steady_clock::now();
    for (int i = 0; i < N; i++) {
        long long f = fare(static_cast<Zone>(i % 3), i % 24);
        if (card.deduct(f)) collected += f; else denied++;
    }
    auto ms = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - t1).count();
    cout << "Journeys " << N << ", denied " << denied << '\n';
    cout << "Collected " << collected << " paise (Rs " << collected / 100 << ")\n";
    cout << "Balance never below Rs 50: " << (card.get() >= MIN_BALANCE ? "YES" : "NO") << '\n';
    cout << "Time " << ms << " ms for " << N << " journeys, O(1) per journey\n";
}
