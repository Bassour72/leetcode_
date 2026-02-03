#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
class Solution 
{
    std::vector<int> _JoinSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        std::vector<int> nums3;
        int i;
        int  j;
        
        
        nums3.reserve(nums1.size() + nums2.size());
        i = 0;
        j = 0;
        while (i < (int)nums1.size() && j < (int)nums2.size()) 
        {
            if (nums1[i] < nums2[j]) 
                nums3.push_back(nums1[i++]);
            else 
                nums3.push_back(nums2[j++]);
        }
        while (i < (int)nums1.size()) 
            nums3.push_back(nums1[i++]);
        while (j < (int)nums2.size()) 
            nums3.push_back(nums2[j++]);
        return (nums3);
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        std::vector<int> nums3;
        int isZero;

        nums3 = _JoinSortedArrays( nums1, nums2);
        if ((nums3.size() % 2 == 1))
            return (nums3[nums3.size() / 2] );
        else
        {
            isZero = nums3[(nums3.size() - 1) / 2 ];
            if (isZero == 0)
                return (0);
            isZero = nums3[(nums3.size() - 1) / 2 ] + nums3[(nums3.size()) / 2 ];
            return (((double)isZero  / 2));

        }
    }
};

int main(void)
    
{
    vector <int> numr1 = {2,2,4,4}; //{1,2,3,4,5,6,7,8};//{1,2,3,4,5};[1,3], nums2 = [2]
     vector <int> numr2 = {2,2,4,4}; //{1,2,3,4,5}; //{6,7,8,9,10,11,12,13,14,15,16,17};
     Solution So;
    cout << "\n" << So.findMedianSortedArrays(numr1, numr2) << endl;
    return 0;
}

