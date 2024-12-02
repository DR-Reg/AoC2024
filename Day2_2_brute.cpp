#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

bool isSafe(vector<int>, int);
int main()
{
    ifstream file("data/Day2.txt");
    string line;
    long count = 0;
    while (getline(file, line))
    {
        istringstream ss(line);
        int n;
        vector<int> levels;
        while (ss >> n)
            levels.push_back(n);

        // bool safe = false;
        // for (int i = -1; i < levels.size(); i++)
        //     safe |= isSafe(levels, i);
        // count += safe;
        bool safe = false;
        cout << levels.size() << endl;
        for (int i = -1; i < 20; i++)
            safe |= isSafe(levels, i);
        count += safe;
    }
    cout << count << endl;
}

bool isSafe(vector<int> levels, int exclude)
{
    bool first = true;
    bool second = true;
    int last = 0;
    int sgn = 0;
    for (int i = 0; i < levels.size(); i++)
    {
        if (i == exclude) continue;
        if (first)
        {
            first = false;
            last = levels[i];
            continue;
        }
        int myDiff = levels[i] - last;
        int amd = abs(myDiff);
        if (amd == 0 || amd > 3)
        {
            return false;
        }
        last = levels[i];
        int mySgn = (myDiff > 0) - (myDiff < 0);
        if (second)
        {
            sgn = mySgn;
            second = false;
            continue;
        }
        if (sgn != mySgn)
        {
            return false;
        }
    }
    return true;
}