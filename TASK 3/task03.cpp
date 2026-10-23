// Task 3 - Data types and type compatibility
#include <iostream>
#include <climits>
using namespace std;

int main()
{
    // 1. Data type for every value (sizes on this system)
    cout << "bool      (flag, peak)       : " << sizeof(bool) << " byte\n";
    cout << "char      (grade 'A')        : " << sizeof(char) << " byte\n";
    cout << "int       (zone, hour)       : " << sizeof(int) << " bytes\n";
    cout << "unsigned  (journey count)    : " << sizeof(unsigned) << " bytes\n";
    cout << "long long (money in paise)   : " << sizeof(long long) << " bytes\n";
    cout << "double    (avg, report only) : " << sizeof(double) << " bytes\n\n";

    // 2. Ranges from <climits>
    cout << "int       : " << INT_MIN << " to " << INT_MAX << '\n';
    cout << "long long : " << LLONG_MIN << " to " << LLONG_MAX << "\n\n";

    // 3. Type compatibility: int + double + bool in one expression
    int i = 5; double d = 2.5; bool b = true;
    cout << "5 + 2.5 + true = " << i + d + b << " (int and bool promoted to double)\n\n";

    // 4. Is int enough for a day's collection? (3,000,000 journeys x Rs 36)
    long long total = 3000000LL * 3600;          // paise
    cout << "Network total = " << total << " paise\n";
    cout << "INT_MAX       = " << INT_MAX << '\n';
    cout << (total > INT_MAX ? "int is NOT enough -> use long long\n\n" : "int is enough\n\n");

    // 5. Precision problem: Rs 10.10 fare added n times
    int n = 3000000;
    double rupees = 0;                           // double rupees
    long long paise = 0;                         // integer paise
    for (int k = 0; k < n; k++) { rupees += 10.10; paise += 1010; }
    cout << "Expected total : " << paise / 100 << "." << paise % 100 << " (paise exact)\n";
    cout.precision(10);
    cout << "double total   : " << fixed << rupees << '\n';
    cout << "double error   : " << rupees - paise / 100.0 << '\n';
    return 0;
}
