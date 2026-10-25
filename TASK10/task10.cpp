// Task 10 - Expectation vs execution: double rupees vs integer paise
#include <climits>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    int counts[] = {20000, 500000, 3000000};
    cout << fixed << setprecision(10);
    for (int n : counts) {
        double rupees = 0; long long paise = 0;
        for (int i = 0; i < n; i++) { rupees += 10.10; paise += 1010; }   // Rs 10.10 each
        double exact = paise / 100.0;
        cout << setw(8) << n << " journeys | paise total Rs " << exact
             << " | double total Rs " << rupees << " | error " << rupees - exact << '\n';
    }
    long long network = 3000000LL * 3600;                                 // 3M journeys x Rs 36
    cout << "\nNetwork total " << network << " paise, INT_MAX " << INT_MAX
         << " -> int overflows: " << (network > INT_MAX ? "YES" : "NO") << '\n';
    cout << "long long holds it: " << (network <= LLONG_MAX ? "YES" : "NO") << '\n';
}
