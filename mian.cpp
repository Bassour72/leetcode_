#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void addAt(string s)
{
    int i =0;
    while (s[i] != '\0')
    {
        std :: cout << char ((int)s[i] + i) ;
		i++;
    }
}
class Solution 
{
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int countConsecutive = 0;
        int i = 0;
        for (int i =0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {   
				 countConsecutive++;
				
			}
            else
            {
                if (i < countConsecutive)
                    i = countConsecutive;
					std :: cout << "==>. "<< i << std::endl;
                countConsecutive = 0;
            }
        }
        
        return  (i > countConsecutive) ? i : countConsecutive ;
    }
};
int main()
{
    std::vector<int> myVector;
	Solution so;
    // Add elements to the vector [1,0,1,1,0,1]
    myVector.push_back(1);
    myVector.push_back(0);
    myVector.push_back(1);
    myVector.push_back(1);
    myVector.push_back(0);
    myVector.push_back(1);
	std::cout << so.findMaxConsecutiveOnes(myVector) << std::endl;
    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

//    addAt(l);
}