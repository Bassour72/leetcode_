#include <iostream>
#include <algorithm>
#include <set>
#include <iostream>
#include <map>
#include <string>

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


// class Solution 
// {
// public:
//    static bool canConstruct(std::string ransomNote, std::string magazine) 
//     {
//         int count = 0;
//         std::map<size_t, char> exist;
//         size_t pos = 0;
//         for (size_t i = 0; i < ransomNote.length(); i++)
//         {
//             size_t it = magazine.find(ransomNote[i], pos);
//             if (it != std::string::npos) 
//             {
//                 if (exist.find(it) == exist.end())
//                 {    
//                     count++; 
//                     pos = 0;
//                     exist.insert(std::make_pair(it, ransomNote[i]));
//                 }
//                 else 
//                 {   
//                     pos = it + 1; 
//                     // std ::cout << pos << " === \n";
//                     i -= 1;
//                 }
//             }
//         }

        
//         return ((int)ransomNote.length() == count);
//     }
// };

// class Solution 
// {
// public:
//    static bool canConstruct(std::string ransomNote, std::string magazine) 
//     {
//         int count = 0;
//         std::set <char > vec(magazine.begin(), magazine.end());
//         std::set<std::set<char >::iterator > exist;

//         for (size_t i = 0; i < ransomNote.length(); i++)
//         {
//             std::set <char > ::iterator it = vec.find(ransomNote[i]);
//             if (it != vec.end() && exist.find(it) == exist.end())
//             {    
//                 count++; 
//                  exist.insert(it);
//             }
//         }
        
//         return ((int)ransomNote.length() == count);
//     }
// };
/*
ransomNote="aab"
magazine="baa"
ransomNote="bg"
magazine="efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj"
*/
int main(void)
{
	std::cout << Solution::canConstruct("aab", "baa") << " | true \n";
	std::cout << Solution::canConstruct("a", "b") << " | false \n";
	std::cout << Solution::canConstruct("aa", "ab") << " | false\n";


	std::cout << Solution::canConstruct("bg", "efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj") << " | true\n";

	return 0;
}
