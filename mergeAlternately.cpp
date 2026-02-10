#include <iostream>


class Solution 
{
public:
    static std::string mergeAlternately(std::string word1, std::string word2) 
    {
        std:: string mergeString ="";
        if (word1.empty() || word2.empty())
            return (word1.empty() ?  word2 : word1);
        int index1 = 0;
        int index2 = 0;
        for (size_t i = 0; i < word1.size() + word2.size(); i++)
        {
            if (i % 2 == 0)
            { 
                if (index1 < (int)word1.size()) 
                    mergeString += (char)word1[index1++]; 
                else if (index2 < (int)word2.size())
                     mergeString += (char)word2[index2++]; 
            }
            else
            { 
                if (index2 < (int)word2.size())
                    mergeString += (char)word2[index2++];
                else if (index1 < (int)word1.size())
                     mergeString += (char)word1[index1++]; 
            }
        }
        return (mergeString);
    }
};


int main(void)
{
    std::string word1 = "abcd";
    std::string word2 = "pq";
    std::cout << "Before merge : " << word1<< "\n";
    std::cout << "Before merge : " << word2<< "\n";
    std::cout << "After merge : \n" << Solution::mergeAlternately(word1, word2) << "\n";
    return 0;
}
