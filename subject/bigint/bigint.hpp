#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <vector>
#include <algorithm>
class bigint
{
private:
    /* data */
    std::vector<int> _nbr;
    std::vector<int> convertUnsignedToVectorInt(unsigned int nbr); //I can use any build-in function in cpp
public:
    size_t convertToInt(std::vector<int>);
    void _PrintNbr();
    std::string _PrintNbr() const;
    bigint();
    bigint(unsigned int nbr);

    bigint( const bigint & other);

    bigint operator=( const bigint & other);

    bigint operator+( const bigint & other) const ;
    bigint &operator+=( const bigint & other);
    bigint &operator++();
    bigint operator++(int);
    bigint operator>>(int);
    bigint operator<<(int);
    bigint operator>>( const bigint & other);
    bigint operator<<( const bigint & other);
    bigint &operator>>=( const bigint & other);
    bigint &operator>>=(int);
    bigint &operator<<=(int);
    bigint &operator<<=( const bigint & other);
    bool operator<( const bigint & other);
    bool operator>( const bigint & other);
    bool operator==( const bigint & other);
    bool operator!=( const bigint & other);
    bool operator<=( const bigint & other);
    bool operator>=( const bigint & other);
    friend std::ostream & operator<<(std::ostream &out, const bigint &other);
    size_t size() const
    {
        return (_nbr.size());
    }
    ~bigint();
};


#endif