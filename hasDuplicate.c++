#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution 
{

public:
    bool hasDuplicate(std::vector<int>& nums)
    {
        std::unordered_set<int> mySet;
        for (int i = 0; i <(int)nums.size(); i++)
        {
            if (mySet.insert(nums[i]).second == false)
                    return (true);
        }
        return (false);
    }
};