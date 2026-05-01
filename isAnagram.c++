#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
class Solution {
public:
   static bool isAnagram(std::string s, std::string t) 
    {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return (!s.compare(t));
    }
};

int main(void)
{
	std::cout << Solution::isAnagram("aa", "a") << "\n";
	std::cout << Solution::isAnagram("aa", "*a") << "\n";

	return 0;
}