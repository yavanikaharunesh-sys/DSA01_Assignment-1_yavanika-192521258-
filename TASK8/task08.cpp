// Task 8 - Safe input and formatted output
#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

int readInt(const char* prompt, int lo, int hi)
{
    int v;
    cout << prompt;
    while (!(cin >> v) || v < lo || v > hi) {
        if (cin.eof()) exit(1);
        cin.clear();                                       // reset error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // discard bad line
        cout << "Invalid input, try again: ";
    }
    return v;
}

int main()
{
    constexpr int BASE_PAISE[] = {1000, 2000, 3000};
    long long balance = 10000;                             // Rs 100.00 in paise

    int hour = readInt("Enter hour (0-23): ", 0, 23);
    int zone = readInt("Enter zone (0=Inner 1=Middle 2=Outer): ", 0, 2);

    bool peak = (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
    long long fare = BASE_PAISE[zone];
    if (peak) fare += fare * 20 / 100;
    balance -= fare;

    cout << "\n--- Journey report ---\n" << fixed << setprecision(2)
         << left << setw(10) << "Hour"  << right << setw(8) << hour << '\n'
         << left << setw(10) << "Zone"  << right << setw(8) << zone << '\n'
         << left << setw(10) << "Peak"  << right << setw(8) << (peak ? "Yes" : "No") << '\n'
         << left << setw(10) << "Fare"  << right << setw(8) << fare / 100.0 << '\n'
         << left << setw(10) << "Balance" << right << setw(8) << balance / 100.0 << '\n';
    return 0;
}
