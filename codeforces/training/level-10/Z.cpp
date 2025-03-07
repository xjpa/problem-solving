// https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/Z

#include <iostream>
#include <algorithm>
/*
approach:
check if input triangle is already right-angled
if not then iterate over each vertex, and try moving it by exactly one unit in each of the four directions
    for each modification, we re-check for both nondegeneracy and the right-angle property
*/
struct Point
{
    int x, y;
};

bool isDegenerate(const Point &a, const Point &b, const Point &c)
{
    return (long long)(a.x - c.x) * (b.y - c.y) - (long long)(a.y - c.y) * (b.x - c.x) == 0;
}

bool isRight(const Point &a, const Point &b, const Point &c)
{
    long long d1 = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    long long d2 = (a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y);
    long long d3 = (b.x - c.x) * (b.x - c.x) + (b.y - c.y) * (b.y - c.y);
    if (d1 == 0 || d2 == 0 || d3 == 0)
        return false;
    long long sides[3] = {d1, d2, d3};
    std::sort(sides, sides + 3);
    return sides[2] == sides[0] + sides[1];
}

int main()
{
    Point a, b, c;
    std::cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    if (isRight(a, b, c))
    {
        std::cout << "RIGHT" << "\n";
        return 0;
    }
    int moves[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < 4; i++)
    {
        Point a2 = {a.x + moves[i][0], a.y + moves[i][1]};
        if (!isDegenerate(a2, b, c) && isRight(a2, b, c))
        {
            std::cout << "ALMOST" << "\n";
            return 0;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        Point b2 = {b.x + moves[i][0], b.y + moves[i][1]};
        if (!isDegenerate(a, b2, c) && isRight(a, b2, c))
        {
            std::cout << "ALMOST" << "\n";
            return 0;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        Point c2 = {c.x + moves[i][0], c.y + moves[i][1]};
        if (!isDegenerate(a, b, c2) && isRight(a, b, c2))
        {
            std::cout << "ALMOST" << "\n";
            return 0;
        }
    }
    std::cout << "NEITHER" << "\n";
    return 0;
}
