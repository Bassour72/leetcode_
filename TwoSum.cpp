#include <iostream>
#include <vector>

class Solution 
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        int sum  = 0;
        std::vector <int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            if (target % nums[i] == 0)
            {
                result.push_back(i);
                return (result);
            }
            else if  (target % nums[i] < target)
            {
                result.push_back(i);
                return (result);
            }
        }
        
        return result;
    }
};

int main(void)
{
       int arr[] = 
       { 
            4, 6, 7, 8, 10, 11, 13, 14, 15, 
            16, 17, 18, 19, 20, 21, 22, 23, 
            24, 25, 26, 27, 28, 100
        };

    std::vector<int> num(arr, arr + sizeof(arr)/sizeof(arr[0]));
    Solution so;
    std::vector<int> cc = so.twoSum(num, 7);
    std::cout << "\n" << cc[0] << "\n";
    return 0;
}
