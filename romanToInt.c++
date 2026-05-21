#include <iostream>
#include <string>
#include <map>
class Solution {
public:
    static int romanToInt(std::string s) 
    {
        std::map<char, int > mp;
        mp.insert(std::pair<char, int>('I', 1));
        mp.insert(std::pair<char, int>('V', 5));    
        mp.insert(std::pair<char, int>('X', 10));    
        mp.insert(std::pair<char, int>('L', 50));    
        mp.insert(std::pair<char, int>('C', 100));    
        mp.insert(std::pair<char, int>('D', 500));    
        mp.insert(std::pair<char, int>('M', 1000));
        int nbr = 0;
        int sub = 0;
        for (size_t i = 0; i < s.length(); i++)
        {
            
            if (mp[s[i]] < mp[s[i + 1]])
            {
                sub = mp[s[i]];
            }
            else
            {
                nbr += mp[s[i]];
                nbr -= sub;
                sub = 0;
            }
        }
        return (nbr);
    }
};
int main(void)
{
    std ::cout << Solution::romanToInt("III") << "\n";
    std ::cout << Solution::romanToInt("LVIIIs") << "\n";
    std ::cout << Solution::romanToInt("MCMXCIV") << "\n";


    return (0);
}
