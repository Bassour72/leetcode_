#include <iostream>
#include <string>
#include <algorithm>

class Solution 
{
public:
    static std::string addBinary(std::string a, std::string b) 
    {   
        std::string strbinary;
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());

        size_t i = 0;
        int curryout = 0;

        while (i < std::max(a.length(), b.length()))
        {
            int digitA = i < a.length() ? a[i] - '0' : 0;
            int digitB = i < b.length() ? b[i] - '0' : 0;
            int total = digitA + digitB + curryout;
            strbinary += (char)((total % 2) + '0');
            curryout = total / 2;

            i++;
        }
        if (curryout)
            strbinary += '1';
        std::reverse(strbinary.begin(), strbinary.end());
        return strbinary;
    }
};
/*
Input: a = "101", b = "10"

Output: "111"

    0
    0
*/
int main()
{
    std::cout << Solution::addBinary("111", "11") << "\n";
    std::cout << Solution::addBinary("11", "1")<< "\n";

}