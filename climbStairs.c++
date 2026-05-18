#include <iostream>
#include <algorithm>
#include <set>
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <string>

class Solution {
public:
    static int climbStairs(int n) 
    {
		int step = 0;
		int stepOne = 1;
		int stepTwo = 0;
		while (n--)
		{
			step = stepOne + stepTwo;
			stepTwo = stepOne;
			stepOne = step;
		}
		return (step);
    }
};


int main(void)
{
  
	// std::cout << Solution::climbStairs(2) << "\n";
	std::cout << Solution::climbStairs(45) << "\n";
	// std::cout << Solution::climbStairs(3) << "\n";
	// std::cout << Solution::climbStairs(5) << "\n";


	return 0;
}
// 1836311903