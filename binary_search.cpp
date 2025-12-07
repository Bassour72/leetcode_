#include <vector>
#include <iostream>
using namespace std;
// class Solution {
// public:
//     int search(vector<int>& nums, int target) 
//     {
//         int found = -1;
//         for (size_t i =0; i < nums.size(); i++)
//         {
//             if (nums[i] == target)
//                 return i;

//         }
//         return found ;
//     }
// };
class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 0, right = nums.size() - 1;

        while (left <= right) 
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};
// Runtime
// 0
// ms
// Beats
// 100.00%
// Analyze Complexity
// Memory
// 31.31
// MB
// Beats
// 45.49%
int main()
{
   int arr[63] = {
    -1, 0, 3, 5, 9, 12, 1, 2, 1, 
    4, 6, 7, 8, 10, 11, 13, 14, 15, 
    16, 17, 18, 19, 20, 21, 22, 23, 
    24, 25, 26, 27, 28,-1, 0, 3, 5, 9, 12, 1, 2, 1, 
    4, 6, 7, 8, 10, 11, 13, 14, 15, 
    16, 17, 18, 19, 20, 21, 22, 23, 
    24, 25, 26, 27, 28, 100};

    vector<int> num(arr, arr + sizeof(arr)/sizeof(arr[0]));
    Solution so;
    cout << so.search(num, 100) << endl;
    return 0;
}
