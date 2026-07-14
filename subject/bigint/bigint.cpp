#include "bigint.hpp"


std::vector<int> bigint::convertUnsignedToVectorInt(unsigned int nbr)
{
    std::vector<int> temp;
    while (nbr > 0)
    {
        int c = nbr % 10;
        _nbr.push_back(c);
        nbr /= 10;
    }
    std::reverse(_nbr.begin(), _nbr.end());
    return (temp);
}


void bigint::_PrintNbr() 
{
    if (_nbr.empty())
        return ;
    std::vector<int>::iterator it = _nbr.begin();

    for ( ; it != _nbr.end(); it++)
    {
        std:: cout << *it ;
    }
    std::cout << "\n";
}

std::string bigint::_PrintNbr() const 
{
    if (_nbr.empty())
        return "";
    std::string temp = "";
    for (size_t i = 0; i < _nbr.size(); i++)
    {
        std::cout << _nbr[i] ;
    }
   return (temp);
}

bigint::bigint()
{
    convertUnsignedToVectorInt(0);
    // _PrintNbr();
}


bigint::bigint(unsigned int nbr)
{
    convertUnsignedToVectorInt(nbr);
    // std:: cout << "size " <<_nbr.size() << "\n\n";

    // _PrintNbr();
}

bigint::bigint( const bigint & other)
{
    // std::cout << "\nCopy constructor call\n";
   _nbr = other._nbr;
}

bigint bigint::operator=( const bigint & other)
{
    // std::cout << "\nCopy Assignment Operator call \n";
    _nbr = other._nbr;
    // _PrintNbr();
    return (*this);
}


bigint bigint::operator+(const bigint & other) const
{
    bigint temp(0);
    std::vector<int>::const_reverse_iterator it1 = _nbr.rbegin();
    std::vector<int>::const_reverse_iterator it2 = other._nbr.rbegin();
    int curr  = 0;
    while (it1 != _nbr.rend() || it2 != other._nbr.rend())
    {
        int c = 0;
        if (it1 != _nbr.rend())
            c += *it1;
        if (it2 != other._nbr.rend())
            c +=  *it2 ;
        c += curr;
        curr = 0;
        if (c >= 10)
        {    
            temp._nbr.push_back(c % 10);
            curr  = c / 10;
        }
        else
            temp._nbr.push_back(c);
        if (it1 != _nbr.rend())
            it1++;
        if (it2 != other._nbr.rend())
            it2++;
    }
    
    std::reverse(temp._nbr.begin(), temp._nbr.end());
    return (temp);
}

bigint &bigint::operator+=( const bigint & other)
{
    *this = this->operator+(other);
    return (*this);
}
/*
std::cout << "(c += a) = " << (c += a) << std::endl;
output "(c += a) = 42
42"
*/
bigint &bigint::operator++()
{
    bigint temp(1);
    *this = this->operator+(temp);
    return (*this);
}

bigint bigint::operator++(int)
{
    bigint temp(1);
    bigint temp1 = *this;
    *this = this->operator+(temp);
    return (temp1);
}


bigint bigint::operator>>(int nbr)
{
   bigint temp = *this;
   
    for (size_t i = 0; (int)i < nbr; i++)
    {
        temp._nbr.pop_back();
    }
    return (temp);
}

size_t bigint::convertToInt(std::vector<int> nbr)
{
    size_t  n = 0;
    for (size_t i = 0; i < nbr.size(); i++)
    {
        n *= 10;
        n += nbr[i];
    }
    return n;
}

bigint bigint::operator<<(int nbr)
{
    bigint temp = *this;
    for (size_t i = 0; (int)i < nbr; i++)
    {
        temp._nbr.push_back(0);
    }
    return (temp);
}

bigint bigint::operator>>( const bigint & other)
{
    bigint temp = *this;
    size_t  n = convertToInt(other._nbr);
    for (size_t i = 0; i < n; i++)
    {
        if (!temp._nbr.empty())
            temp._nbr.pop_back();
    }
    return (temp);
}

bigint bigint::operator<<( const bigint & other)
{
    bigint temp = *this; 
    size_t  n = convertToInt(other._nbr);
    for (size_t i = 0; i < n; i++)
    {
        temp._nbr.push_back(0);
    }
    
    return (temp);
}

bigint &bigint::operator>>=( const bigint & other)
{
   
    *this = this->operator>>(other);
    return (*this);
}

bigint &bigint::operator>>=(int nbr)
{
    *this = this->operator>>(nbr);
    return (*this);
}

bigint &bigint::operator<<=(int nbr)
{
    *this = this->operator<<(nbr);
    return (*this);
}


bigint &bigint::operator<<=( const bigint & other)
{
    *this = this->operator<<(other);
    return (*this);
}


bool bigint::operator <( const bigint & other)
{
    if (_nbr.size() < other._nbr.size())
        return (true);
    else if (_nbr.size() > other._nbr.size())
        return (false);
    else
        return (_nbr[0] < other._nbr[0]);
}


bool bigint::operator>( const bigint & other)
{
    if (_nbr.size() > other._nbr.size())
        return (true);
    else if (_nbr.size() < other._nbr.size())
        return (false);
    else
        return (_nbr[0] > other._nbr[0]);
}

bool bigint::operator==( const bigint & other)
{
    if (this == &other)
        return (true);
    for (int i = _nbr.size()  - 1; i >= 0; i--)
    {
        if (static_cast<int>(_nbr[i]) != static_cast<int>(other._nbr[i]))
            return (false);
    }
    return (true);
}


bool bigint::operator!=( const bigint & other)
{
    return (!this->operator==(other));
}

bool bigint::operator<=( const bigint & other)
{
    return (this->operator<(other)?true: this->operator==(other)?true:false);
}

bool bigint::operator>=( const bigint & other)
{
    return (this->operator>(other)?true: this->operator==(other)?true:false);
}

std::ostream &operator<<(std::ostream &out, const bigint &other)
{
    for (size_t i = 0; i < other._nbr.size(); i++)
    {
        out << other._nbr[i];
    }
    return out;
}

bigint::~bigint()
{
}
