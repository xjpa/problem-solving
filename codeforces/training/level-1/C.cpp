// https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/C
/*
approach:
just print and do math operations
apparently they have a large input so i'll use long long
 */

#include <iostream>
int main()
{
    long long x, y;
    std::cin >> x >> y;
    std::cout << x << " + " << y << " = " << (x + y) << "\n";
    std::cout << x << " * " << y << " = " << (x * y) << "\n";
    std::cout << x << " - " << y << " = " << (x - y) << "\n";
    return 0;
}