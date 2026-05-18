
#include <iostream>
#include <string>
#include <set>
#include <iterator>
class Solution 
{
     static int countDup(const std::string &s, char c)
    {
        int i = 0;
        int see = 0;
         while (i < (int)s.length())
        {
            if (s[i] == c)
                    see++;
            i++;
        }
        return (see);
    }
public:
    static int longestPalindrome(std::string s) 
    {
       int len = 0;
       std::set<char> mp;
       mp.insert(s.begin(), s.end());
       std::set<char>::iterator it;
       it = mp.begin();
       bool isOdd = true;
        for (; it != mp.end(); it++)
        {
          
            short add = countDup(s, *it);
            if ((add & 1) == 0)
               len += add;
            else if ((add & 1) != 0)
            {
                if (isOdd == true)
                    len++;
                if (add > 2)
                    len += (add - 1);
                isOdd = false;
            }
        }
        return (len);
    }
};
int main(void)
{
  
	std::cout << Solution::longestPalindrome("abccccdd") << "\n";
	std::cout << Solution::longestPalindrome("bb") << "\n";
	std::cout << Solution::longestPalindrome("ccc") << "\n";
	std::cout << Solution::longestPalindrome("bananas") << "\n";
	// std::cout << Solution::climbStairs(5) << "\n"; dccaccd

	return 0;
}