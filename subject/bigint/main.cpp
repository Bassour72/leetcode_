// const previouslyMaxSafeInteger = 9007199254740991n;

// const alsoHuge = BigInt(9007199254740991);
// // 9007199254740991n

// const hugeString = BigInt("9007199254740991");
// // 9007199254740991n

// const hugeHex = BigInt("0x1fffffffffffff");
// // 9007199254740991n

// const hugeOctal = BigInt("0o377777777777777777");
// // 9007199254740991n

// const hugeBin = BigInt(
//   "0b11111111111111111111111111111111111111111111111111111",
// );
// // 9007199254740991n

#include <iostream>
#include "bigint.hpp"
// int main()
// {
//     bigint nbr1(12345);
//     bigint nbr2 = nbr1;
//     std::cout << "\n";
//     nbr2._PrintNbr();

//     std:: cout << "After add to bigint \n";
//     bigint nbr3 = nbr1 + nbr2;
//     nbr3._PrintNbr(); 

//     std:: cout << "After add to bigint1 to bigint2 \n";
//     nbr1 +=nbr2;
//     nbr1._PrintNbr();

//     std:: cout << "After add to bigint1 by one \n";
//     ++nbr1;
//     nbr1._PrintNbr();

//      std:: cout << "After add to bigint1 by one \n";
//     nbr1++;
//     nbr1++;
//     nbr1++;
//     nbr1++;

//     nbr1._PrintNbr();
//     nbr2._PrintNbr();
//     std :: cout  << (nbr2 < nbr1);
//     return 0;
// }



int main(void)
{
	const bigint a(42);
	bigint b(21), c, d(1337), e(d);

	// base test
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;
    
	std::cout << "a + b = " << (a + b) << std::endl;
	std::cout << "a + c = " << a + c << std::endl;
	std::cout << "(c += a) = " << (c += a) << std::endl;
	std::cout << "(c += a) = " << (c) << std::endl;

	std::cout << "b = " << b << std::endl;
	std::cout << "++b = " << ++b << std::endl;
	std::cout << "b++ = " << b++ << std::endl;
	
	// // b = 23, b << 10 -> 23000000000 + 42 = 23000000042
	std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << std::endl;
    
	std::cout << "(d <<= 4) = " << (d <<= 4) << ", d: " << d << std::endl;
	std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << ", d: " << d << std::endl;

	std::cout << "a = " << a << std::endl; // a = 42
	std::cout << "d = " << d << std::endl; // d = 5348

	std::cout << "(d < a) = " << (d < a) << std::endl; // (d < a) = 0
	std::cout << "(d > a) = " << (d > a) << std::endl; // (d > a) = 1
	std::cout << "(d == d) = " << (d == d) << std::endl; // (d == d) = 1
	std::cout << "(d != a) = " << (d != a) << std::endl; // (d != a) = 1
	std::cout << "(d <= a) = " << (d <= a) << std::endl; // (d <= a) = 0
	std::cout << "(d >= a) = " << (d >= a) << std::endl; // (d >= a) = 1

	// // extra
	bigint x(12345678); bigint y(5);
	std::cout << "(x << y) = " << (x << y) << ", x: " << x << ", y: " << y << std::endl;
	std::cout << "(x >>= y) = " << (x >>= y) << ", x: " << x << ", y: " << y << std::endl;
	std::cout << "(x >= y) = " << (x >= y) << ", x: " << x << ", y: " << y << std::endl;

	std::cout << "x= " << (x <<= 5) << ", y= " << (y <<= 12) << std::endl;
	std::cout << "(x >= y) = " << (x >= y) << ", x: " << x << ", y: " << y << std::endl;

	return (0);
}
