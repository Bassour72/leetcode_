#include <iostream>
#include <algorithm>
#include <set>
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <string>

class Solution 
{
public:
    static bool canConstruct(std::string ransomNote, std::string magazine) 
    {
        int letterCounts[26] = {0};
        for (size_t i = 0; i < magazine.length(); ++i) 
            letterCounts[magazine[i] - 'a']++;
        
        for (size_t i = 0; i < ransomNote.length(); ++i) 
        {
            int index = ransomNote[i] - 'a';
            if (--letterCounts[index] < 0) 
            {
                return false;
            }
        }
         
        return true;
    }
};


int main(void)
{
  
	std::cout << Solution::canConstruct("a", "b") << " | false \n";
	std::cout << Solution::canConstruct("aa", "ab") << " | false\n";


	std::cout << Solution::canConstruct("bg", "efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj") << " | true\n";

	return 0;
}
