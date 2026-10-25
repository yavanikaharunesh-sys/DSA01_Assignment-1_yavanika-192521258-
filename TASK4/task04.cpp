// Task 4 - Implicit conversions (given program)
#include <iostream>

int main()
{
    int a = 7, b = 2;
    double c = a / b;                        // integer division, then int -> double
    double d = static_cast<double>(a) / b;   // explicit cast first, so real division
    std::cout << c << ' ' << d << '\n';

    char ch = 'A' + 2;                       // int 67 stored back in char
    std::cout << ch << ' ' << ch + 1 << '\n';  // ch + 1 is int (promotion)

    bool flag = 5;                           // any non-zero int -> true
    std::cout << flag << ' ' << std::boolalpha << flag << '\n';

    unsigned int u = 1;
    int s = -1;
    std::cout << (s < u ? "s < u" : "s >= u") << '\n';  // s converted to unsigned
}
