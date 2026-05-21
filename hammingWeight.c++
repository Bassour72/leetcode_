#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
class Solution {
   
public:
    static int hammingWeight(int n) 
    {
        n = n - ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = (n + (n >> 4)) & 0x0F0F0F0F;
        n = n + (n >> 8);
        n = n + (n >> 16);
        return n & 0x3F;
    }

};

/*
class Solution {
public:
    int hammingWeight(uint32_t n) {
 return __builtin_popcount(n);
    }
};

*/

/*
class Solution {
public:
    int hammingWeight(int n) 
    {
        int i = 0;
        while (n > 0)
        {
            if ( n % 2 != 0)
                i++;
            n /= 2;
        }
        return i;
    }
};
*/