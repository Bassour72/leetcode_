#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maximumCount(vector<int>& nums) 
    {
        int count_pos = 0;
        int count_neg = 0;
        for (size_t i =0; i< nums.size(); i++)
        {
            if (nums[i] < 0)
                count_neg++;
            if (nums[i] > 0)
                count_pos++;
        }
        return (count_pos > count_neg? count_pos : count_neg);
    }
};
int main()
{
    int arr[63] = {
    -1,- 0,- 3,- 5,- 9, -12,- 1,- 2,- 1, 
   - 4,- 6,- 7,- 8, -10, -11, -13, -14, -15, 
    -16, -17, -18, -19, -20, -21, -22, -23, 
    -24, -25, -26, -27, -28,-1,- 0,- 3,- 5,- 9, -12,- 1,- 2,- 1, 
    4, 6, 7, 8, 10, 11, 13, 14, 15, 
    16, 17, 18, 19, 20, 21, 22, 23, 
    24, 25, 26, 27, 28, 100};

    vector<int> num(arr, arr + sizeof(arr)/sizeof(arr[0]));
    Solution so;
    cout << so.maximumCount(num) << endl;
    return 0;
}
