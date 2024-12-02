#include <fstream>
#include <sstream>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
int main()
{
    ifstream file("Day2.txt");
    string line;
    int count = 0;
    while (getline(file, line))
    {
        istringstream ss(line);
        int n, sgn, last;
        bool first = true;
        bool second = true;
        set<int> problems;
        vector<int> nums;
        for (int ix = 0; ss >> n; ix++)
        {
            nums.push_back(n);
            if (first)
            {
                last = n;
                first = false;
                continue;
            }
            int myDiff = n - last;
            int amd = abs(myDiff);
            if (amd == 0 || amd > 3)
            {
                problems.insert(ix);
            }
            last = n;
            int mySgn = (myDiff > 0) - (myDiff < 0); 
            if (second && !first)
            {
                sgn = mySgn;
                second = false;
                continue;
            }
            if (mySgn != sgn)
            {
                problems.insert(ix);
            }
        }
        if (problems.size() == 0)
        {
            count++;
            continue;
        }
        if (problems.size() > 1)
            continue;
        bool safe = false;
        for (int i : problems) // only one
        {
            if (i == nums.size() - 1)
            {
                safe = true;
                break;
            }
            int myDiff = nums[i + 1] - nums[i - 1];
            int mySgn = (myDiff > 0) - (myDiff < 0); 
            int amd = abs(myDiff);
            if (!(amd == 0 || amd > 3 || mySgn != sgn))
                safe = true;
        }
        count += safe;
    }
    cout << count << endl;
}