#include <iostream>
#include <vector>
class Solution {
public:
    static void moveZeroes(std::vector<int>& nums) 
    {
        int left = 0;

        for (int right = 0; right < (int)nums.size(); right++)
        {
            
            if (nums[right] != 0)
            {
                std::swap(nums[left], nums[right]);
                left++;
            }
        }
    }
};