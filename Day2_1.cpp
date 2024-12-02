#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;
int main()
{
    ifstream file("data/Day2.txt");
    string line;
    int count = 0;
    while (getline(file, line))
    {
        istringstream ss(line);
        int n, sgn, last;
        bool first = true;
        bool second = true;
        bool safe = true;
        while (ss >> n)
        {
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
                safe = false; 
                break;
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
                safe = false; 
                break;
            }
        }
        count += safe;
    }
    cout << count << endl;
}