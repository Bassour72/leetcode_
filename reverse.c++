#include <iostream>

class Solution {
public:
	static int reverse(int x) 
	{
		long		Result;
		short	sign;
		long	nbr;
		Result = 0;
		sign = 1;
		nbr = x;
		std::cout << nbr << "\n";
		
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
};

int main(void)
{
	std::cout << Solution::reverse(123) << "\n";
	std::cout << Solution::reverse(1534236469) << "\n";

	return 0;
}
