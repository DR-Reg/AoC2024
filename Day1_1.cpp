#include <fstream>
#include <iostream>
#include <queue>

int main()
{
    std::ifstream file("Day1.txt");
    long l,r;
    std::priority_queue<int> left, right;
    while (file >> l >> r)
    {
        left.push(l);
        right.push(r);
    }
    long total_diff = 0;
    while (!left.empty())
    {
        l = left.top();
        r = right.top();
        total_diff += labs(l - r);
        left.pop();
        right.pop();
    }
    std::cout << total_diff << std::endl;
    return 0;
}