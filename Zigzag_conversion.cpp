#include <vector>
#include <iostream>
#include <string>

class Solution 
{

public:
    std::string convert(std::string s, int numRows) 
    {
        int len = (int)s.size() * (numRows) + numRows;
        std::string s1;
        s1.reserve(len );
        int j = 0;
        for (int i = 0; i < numRows; i++)
        {
            s1[i] = '\n';
        }
        
    }
};

int main(void)
{
    /* code */
    return 0;
}
