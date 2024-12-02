#include <fstream>
#include <iostream>
#include <map>
#include <set>

int main()
{
    std::ifstream file("data/Day1.txt");
    long l,r;
    std::set<int> left;
    std::map<int, int> right;
    while (file >> l >> r)
    {
        left.insert(l);
        right[r]++;
    }
    long total_sim = 0;
    for (int l : left)
        total_sim += right[l] * l;
    std::cout << total_sim << std::endl;
    return 0;
}