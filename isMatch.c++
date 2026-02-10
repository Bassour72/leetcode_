#include <iostream>


class Solution {
public:
   static bool isMatch(std::string s, std::string p) 
    {
        if (p.find('*') != std::string::npos)
            return (true);
        else if (p.find('.') != std::string::npos)
        {
            /* code */
        }
        
        (void)s;
        return (true);
    }
};

int main(void)
{
	std::cout << Solution::isMatch("aa", "a") << "\n";
	std::cout << Solution::isMatch("aa", "*a") << "\n";

	return 0;
}