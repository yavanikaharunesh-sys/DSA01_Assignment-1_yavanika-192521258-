// Task 9 - Implement and test the fare logic (table-driven tests)
#include <iostream>
#include <sstream>
using namespace std;

constexpr int BASE_PAISE[] = {1000, 2000, 3000};
constexpr long long MIN_BALANCE = 5000;

bool isPeak(int h) { return (h >= 8 && h < 10) || (h >= 17 && h < 20); }

long long fare(int zone, int hour)                 // -1 = invalid input
{
    if (zone < 0 || zone > 2 || hour < 0 || hour > 23) return -1;
    long long f = BASE_PAISE[zone];
    return isPeak(hour) ? f + f * 20 / 100 : f;
}
bool canTravel(long long bal, long long f) { return bal - f >= MIN_BALANCE; }
bool recharge(long long& bal, long long amt) { if (amt <= 0) return false; bal += amt; return true; }

int main()
{
    struct T { const char* name; int zone, hour; long long expected; };
    T tests[] = {
        {"Inner  12:00 off-peak", 0, 12, 1000}, {"Middle 12:00 off-peak", 1, 12, 2000},
        {"Outer  12:00 off-peak", 2, 12, 3000}, {"Inner  09:00 peak    ", 0, 9, 1200},
        {"Outer  18:00 peak    ", 2, 18, 3600}, {"Inner  08:00 boundary", 0, 8, 1200},
        {"Inner  10:00 boundary", 0, 10, 1000}, {"Inner  17:00 boundary", 0, 17, 1200},
        {"Inner  20:00 boundary", 0, 20, 1000}, {"Unknown zone 3      ", 3, 12, -1}};
    int pass = 0, n = sizeof(tests) / sizeof(tests[0]);
    for (const T& t : tests) {
        long long got = fare(t.zone, t.hour);
        bool ok = got == t.expected;
        pass += ok;
        cout << t.name << " expected " << t.expected << " got " << got << (ok ? "  PASS\n" : "  FAIL\n");
    }

    cout << "Leaves exactly Rs 50 : " << (canTravel(6000, 1000) ? "PASS (allowed)" : "FAIL") << '\n';
    cout << "Leaves Rs 49.99      : " << (!canTravel(5999, 1000) ? "PASS (denied)" : "FAIL") << '\n';
    long long bal = 6000;
    cout << "Recharge -500        : " << (!recharge(bal, -500) ? "PASS (rejected)" : "FAIL") << '\n';
    int hour; istringstream in("ab");
    cout << "Hour typed as 'ab'   : " << (!(in >> hour) ? "PASS (rejected)" : "FAIL") << '\n';

    long long total = fare(0, 12) + fare(1, 9) + fare(2, 18) + fare(2, 12) + fare(0, 10);
    cout << "5 journeys total     : " << total << " paise, hand-calculated 1000+2400+3600+3000+1000 = 11000 "
         << (total == 11000 ? "PASS\n" : "FAIL\n");
    cout << pass << "/" << n << " table tests passed\n";
}
