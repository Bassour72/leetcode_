#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if (nums1.size() > nums2.size()) 
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();
        int left = 0;
        int right = m;
        int half = (m + n + 1) / 2;

        while (left <= right)
        {
            int i = (left + right) / 2;
            int j = half - i;

            int left1 = (i > 0) ? nums1[i - 1] : INT_MIN;
            int right1 = (i < m) ? nums1[i] : INT_MAX;

            int left2 = (j > 0) ? nums2[j - 1] : INT_MIN;
            int right2 = (j < n) ? nums2[j] : INT_MAX;
            cout << "end\n";
            if (left1 <= right2 && left2 <= right1)
            {
                if ((m + n) % 2 == 0)
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                else
                    return max(left1, left2);
            } 
            else if (left1 > right2)
                right = i - 1;
            else 
                left = i + 1;

        }
        return 0.0;
    }
};

int main(void)
    
{
    vector <int> numr1 = {1,2,3,4,5,6,7,8};//{1,2,3,4,5};
     vector <int> numr2 = {1,2,3,4,5}; //{6,7,8,9,10,11,12,13,14,15,16,17};
     Solution So;
    cout << "\n" << So.findMedianSortedArrays(numr1, numr2) << endl;
    return 0;
}

