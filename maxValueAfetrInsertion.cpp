#include <iostream>
class Solution 
{
private:
    int getBestPosition(const std::string &s, int x)
    {
        int pos = 0;
    
        if (!s.empty() && s[0] == '-')
        {
            pos = 1;
            while (pos < (int)s.size() && s[pos] - '0' <= x)
                pos++;
        }
        else
        {
            while (pos < (int)s.size() && s[pos] - '0' >= x)
                pos++;
        }
        return pos;
    }

public:
    std::string maxValue(std::string n, int x) 
    {
        int pos = getBestPosition(n, x);
        n.insert(pos, 1, static_cast<char>(x + '0'));
        return n;
    }
};



int main()
{



    Solution so;
    std::cout << so.maxValue( "99",  9) << "\n";
    std::cout << so.maxValue("-13", 2) << "\n";
    std::cout << so.maxValue("-56", 2) << "\n";
    std::cout << so.maxValue("-13", 2) << "\n";
    std::cout << so.maxValue("73", 6) << "\n";
    std::cout << so.maxValue("-132", 3) << "\n";

    return 0;
}
