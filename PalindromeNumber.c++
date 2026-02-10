#include <iostream>

class Solution 
{
private:
    static int reverse(int x) 
	{
		long		Result;
		short	sign;
		long	nbr;
		Result = 0;
		sign = 1;
		nbr = x;	
		if (nbr < 0 ) 
		{
			nbr *= -1;
			sign = -1;
		}
		while (nbr > 0)
		{
			Result = Result * 10 + (nbr % 10);
			if (Result >= 2147483647) 
				return 0;
			nbr /=10;
		}
		return (Result * sign);	
	}
public:
    static bool isPalindrome(int x) 
    {
        return (x < 0)? false : reverse(x) == x ? true : false;   
    }
};
int main(void)
{
	std::cout << Solution::isPalindrome(121) << "\n";
	std::cout << Solution::isPalindrome(1534236469) << "\n";

	return 0;
}
