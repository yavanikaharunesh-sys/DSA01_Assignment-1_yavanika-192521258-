// Task 5 - Operators and precedence (given program)
#include <iostream>

int main()
{
    int x = 5, y = 3;
    std::cout << x + y * 2 << ' ' << (x + y) * 2 << '\n';   // * before +, brackets first

    int z = x++ + ++y;                       // post: use 5 then x=6, pre: y=4 then use
    std::cout << z << ' ' << x << ' ' << y << '\n';

    std::cout << (x > y ? x : y) << ' ' << x % 4 * 2 << '\n';  // % and * left to right
    std::cout << 10 / 3 << ' ' << 10 % 3 << ' ' << -10 / 3 << ' ' << -10 % 3 << '\n';

    int k = 0;
    for (int i = 0; i < 10; i += 3) k += i;  // i = 0, 3, 6, 9
    std::cout << k << '\n';
}
