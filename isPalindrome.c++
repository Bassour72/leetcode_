#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
class Solution {
public:
    static bool isPalindrome(std::string s) 
    {
        std::string str = "";
        std:: string rev = "";
        if (s.empty())
            return (false);
        for (int i = 0; i < s.length(); i++)
        {
            if (isalnum(s[i]))
            {    
                str += tolower(s[i]);
            }
        }
        rev = str;
        std::reverse(rev.begin(), rev.end());
        return str == rev;
    }
};
// class Solution {
// public:
//     static bool isPalindrome(std::string s) 
//     {
//        std:: string ss;
//         if (s.empty())
//             return (false);
//         for (int i = 0; i < s.length(); i++)
//         {
//             if (isalpha(s[i]) && ss[i] != ss[ss.length() -i - 1])
//                  return (false);
//         }
//         return (true);
//     }
// };

int main(void)
{
    std::cout << Solution::isPalindrome("A man, a plan, a canal: Panama") << '\n';
}