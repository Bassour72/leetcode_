
#include <iostream>
#include <string>
#include <algorithm>
class Solution {
public:
    static bool backspaceCompare(std::string s, std::string t) 
    {
        if (s.empty() || t.empty())
            return (false);

        int space_s = 0;
        int space_tt = 0;

        for (int  i = (int)s.length(); i >= 0;i--)
        {
            if (s[i] == '#')
            {
                s.erase(i, 1);
                space_s++;
            }
            else if (std::isalpha(s[i]) && space_s > 0)
            {
                s.erase(i, 1);
                space_s--;
            }
            
                
        }
        for (int  i = (int) t.length(); i >= 0; i--)
        {
            if (t[i] == '#')
            {
                t.erase(i, 1);
                space_tt++;
            }
            else if (std::isalpha(t[i]) && space_tt > 0)
            {
                t.erase(i, 1);
                space_tt--;
            }
        }
        return (!s.compare(t));
    }
};