#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>
#include <vector>

// class Solution {
// public:
//     static int majorityElement(std::vector<int>& nums) 
//     {
//         std::map <int, int> mp;
//         std::vector<int>::iterator it = nums.begin();
//         int is = 1;
//         int count = 0;
//         for ( ; it != nums.end(); it++)
//         {
//             if (mp[*it]++ > count)
//             {
//                 count = mp[*it];
//                 is = *it;
//            }
//         }
//         return (is);
//     }
// };

class Solution {
public:
    static int majorityElement(std::vector<int>& nums)
    {
        std::map<int, int> mp;
        int majority = nums[0];
        int maxCount = 0;

        for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
        {
            mp[*it]++;
            if (mp[*it] > maxCount)
            {
                maxCount = mp[*it];
                majority = *it;
            }
        }
        return (majority);
    }
};
int main()
{
    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> v3;
    std::vector<int> v4;

    int arr1[] = {5,5,1,1,1,5,5};
    int arr2[] = {2,2,1,1,1,2,2};
    int arr3[] = {3,2,3};
    // int arr4[] = {2,2,2}; = {8,8,7,7,7}
    int arr4[] =  {8,8,7,7,7};

    v1.assign(arr1, arr1 + 7);
    v2.assign(arr2, arr2 + 7);
    v3.assign(arr3, arr3 + 3);
    v4.assign(arr4, arr4 + 5);
   std::cout <<  Solution::majorityElement(v4) << "\n";
    return 0;
}