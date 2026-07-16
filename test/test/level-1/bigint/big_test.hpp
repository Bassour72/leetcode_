#ifndef BIG_HPP
#define BIG_HPP
#include <string>
#include <ostream>
#include <sstream>
#include <iostream>
class bigint
{
private:
    std::string _nbr;
    // unsigned int _stringToInt(std::string nbr);
    // std::string _Addtion(const bigint & obj1, const bigint &obj2);
    // std::string _revers(std::string s);
    std::string _intToString(unsigned int);

public:
    bigint();
    bigint(unsigned int);
    bigint(const bigint& other);
    bigint &operator=(const bigint & other);
    bigint operator+(const bigint & other) const;
    bigint &operator += (const bigint & other);
    bigint &operator++();
    bigint operator++(int);
    bigint operator <<(unsigned int) const;
    bigint operator >> (unsigned int) const;
    bigint &operator <<=(unsigned int);
    bigint &operator >>=(unsigned int);
    bigint operator << (const bigint &other) const;
    bigint operator >> (const bigint &other) const;

    bigint &operator <<= (const bigint &other);
    bigint &operator >>= (const bigint &other);
    std::string GetString() const;
    bool operator==(const bigint& other) const;
    bool operator!=(const bigint& other) const;
    bool operator<(const bigint& other) const;
    bool operator>(const bigint& other) const;
    bool operator<=(const bigint& other) const;
    bool operator>=(const bigint& other) const;

    ~bigint();
};

std::ostream & operator << (std::ostream & os, const bigint &other);


#endif