#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
class Solution {
    static int hammingWeight(int n) 
    {
        n = n - ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = (n + (n >> 4)) & 0x0F0F0F0F;
        n = n + (n >> 8);
        n = n + (n >> 16);
        return n & 0x3F;
    }
public:
    static std::vector<int> countBits(int n)
    {
        std::vector<int> nbr;
        int num = 0;
        while (num <= n)
        {
            nbr.push_back(hammingWeight(num));
            num++;
        }
        return (nbr);
    }

};