#include <iostream>
#include <stdint.h>
class Solution
{
public:
    static uint32_t reverseBits(uint32_t n)
    {
        uint32_t result = 0;

        for (short i = 0; i < 32; i++)
        {
            result <<= 1;
            result |= (n & 1); 
            n >>= 1;
        }
        return result;
    }
};