// https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/B
/*
approach:
read input: int, long long, char, float, double
output them line by line
 */

#include <iostream>

int main()
{
    int i;
    long long ll;
    char c;
    float f;
    double d;
    std::cin >> i >> ll >> c >> f >> d;
    std::cout << i << "\n"
              << ll << "\n"
              << c << "\n"
              << f << "\n"
              << d;
    return 0;
}