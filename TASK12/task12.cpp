// Task 12 - Changed requirement: Airport zone, weekend discount, monthly pass
#include <iostream>
using namespace std;

enum class Zone { Inner, Middle, Outer, Airport };               // 4th zone added
constexpr long long BASE_PAISE[] = {1000, 2000, 3000, 6000};     // Airport Rs 60
constexpr int PEAK_PERCENT = 20, WEEKEND_DISCOUNT = 10;

struct Pass { Zone a, b; bool covers(Zone z) const { return z == a || z == b; } };  // 2 chosen zones

bool isPeak(int h) { return (h >= 8 && h < 10) || (h >= 17 && h < 20); }

// Weekend discount never combines with peak surcharge: peak hours keep the surcharge only
long long fare(Zone z, int hour, bool weekend, const Pass* pass = nullptr)
{
    if (pass && pass->covers(z)) return 0;                      // unlimited journeys
    long long f = BASE_PAISE[static_cast<int>(z)];
    if (isPeak(hour)) return f + f * PEAK_PERCENT / 100;
    return weekend ? f - f * WEEKEND_DISCOUNT / 100 : f;
}

int main()
{
    Pass pass{Zone::Inner, Zone::Middle};
    struct T { const char* name; long long got, expected; };
    T t[] = {
        {"Airport weekday 12:00      ", fare(Zone::Airport, 12, false), 6000},
        {"Airport weekday 09:00 peak ", fare(Zone::Airport, 9, false), 7200},
        {"Middle weekend 12:00 (-10%)", fare(Zone::Middle, 12, true), 1800},
        {"Outer weekend 18:00 peak   ", fare(Zone::Outer, 18, true), 3600},
        {"Pass: Middle journey       ", fare(Zone::Middle, 12, false, &pass), 0},
        {"Pass: Outer not covered    ", fare(Zone::Outer, 12, false, &pass), 3000}};
    int ok = 0;
    for (const T& x : t) {
        ok += x.got == x.expected;
        cout << x.name << " expected " << x.expected << " got " << x.got
             << (x.got == x.expected ? "  PASS\n" : "  FAIL\n");
    }
    cout << ok << "/6 passed. Decision: MODIFY - keep constexpr table + SmartCard, extend table to 4 zones,\n"
         << "add a separate discount rule and a Pass class.\n";
}
