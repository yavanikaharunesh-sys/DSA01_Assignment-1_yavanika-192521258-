// Task 2 - Tokens and Constants
#include <iostream>
using namespace std;

#define FARE_DEF 1000                  // macro: no type, no scope
#define SQUARE_BAD(x) x * x            // macro trap

constexpr int BASE_PAISE[] = {1000, 2000, 3000};   // fares in ONE place
constexpr int PEAK_PERCENT = 20;
constexpr long long MIN_BALANCE = 5000;            // Rs 50

enum OldZone { INNER, MIDDLE, OUTER };             // unscoped enum
enum class Zone { Inner, Middle, Outer };          // scoped, safer

int main()
{
    // Tokens in:  long long f = BASE_PAISE[1] + 20;
    // keywords: long   identifiers: f, BASE_PAISE   constants: 1, 20
    // operators: = +   punctuators: [ ] ;
    long long f = BASE_PAISE[1] + 20;
    cout << "f = " << f << '\n';

    cout << "SQUARE_BAD(2+3) = " << SQUARE_BAD(2+3) << " (wrong, expands to 2+3*2+3)\n";
    cout << "sizeof(FARE_DEF) = " << sizeof(FARE_DEF)
         << ", sizeof(BASE_PAISE) = " << sizeof(BASE_PAISE) << '\n';

    int a = OUTER;                                 // enum converts silently to int
    cout << "OUTER as int = " << a << ", OUTER == 2 is " << (OUTER == 2) << '\n';
    // int b = Zone::Outer;                        // ERROR: enum class blocks this
    cout << "Zone::Outer needs a cast = " << static_cast<int>(Zone::Outer) << '\n';

    cout << "Peak surcharge " << PEAK_PERCENT << "%, min balance Rs "
         << MIN_BALANCE / 100 << '\n';
    return 0;
}
