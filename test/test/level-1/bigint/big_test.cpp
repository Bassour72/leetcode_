#include "big_test.hpp"

unsigned int _stringToInt(const std::string &nbr)
{
    std::stringstream s(nbr);
    unsigned int r = 0;
    s >> r;
    return (r);
}

std::string _revers(std::string s)
{
    std::string r = "";
    for (int i = s.length() - 1; i >= 0; i--)
    {
       r.push_back(s[i]);
    }
    return (r);
}

std::string _Addtion(const bigint & obj1, const bigint &obj2)
{
    std::string str1 = _revers(obj1.GetString());
    std::string str2  = _revers(obj2.GetString());

    int len1 = str1.length();
    int len2 = str2.length();
    if (len1 > len2)
    {
        int diff = len1 - len2;
        while (diff > 0)
        {
            str2.push_back('0');
            diff--;
        }
        
    }
    else if (len2 > len1)
    {
        int diff = len2 - len1;
        while (diff > 0)
        {
            str1.push_back('0');
            diff--;

        }
    }
    int cur = 0;
    int d1 = 0;
    int d2 = 0;
    std::string result = "";
    for (size_t i = 0; i < str1.length(); i++)
    {
        d1 = str1[i] - '0';
        d2 = str2[i] - '0';

        int re = d1 + d2 + cur;

        if (re > 9)
        {
            cur = re / 10;
            result.push_back((re % 10) + '0');
        }
        else
            result.push_back((re % 10) + '0');

    }
    
    if (cur != 0)
        result.push_back(cur +  '0');
    
    return (_revers(result));
}

std::string bigint::_intToString(unsigned int nbr)
{
    std::stringstream ss;

    ss << nbr;
    std::string s;
    s = ss.str();
    return (s);
}


bigint::bigint()
{
    _nbr = "0";
}

bigint::bigint(unsigned int num)
{
    _nbr = _intToString(num);

}

bigint::bigint(const bigint& other)
{
    if (this == &other)
        return ;
    _nbr = other._nbr;
}

bigint& bigint::operator=(const bigint& other)
{
    if (this == &other)
        return (*this);
    _nbr = other._nbr;
    return (*this);
}
 std::string bigint::GetString() const
 {
    return(_nbr);
 }
		
bigint bigint::operator+(const bigint& other) const
{
    bigint temp(*this);
    std::string r = _Addtion(temp, other);
    temp._nbr = r;    
    return (temp);
}

bigint& bigint::operator+=(const bigint& other)
{
    this->_nbr = _Addtion(*this, other);
    return (*this);
}

bigint& bigint::operator++()
{
    bigint temp(1);
   this->_nbr = _Addtion(*this, temp);
    return (*this);
}
bigint bigint::operator++(int)
{
    bigint temp(*this);
    this->_nbr = _Addtion(*this , bigint(1));
    return (temp);
}


bigint bigint::operator<<(unsigned int n) const
{
    bigint temp(*this);
    temp._nbr.insert(temp._nbr.end(), n, '0');
    return (temp);
}

bigint bigint::operator>>(unsigned int n)const
{
    bigint temp(*this);
    unsigned int len = _nbr.length();
    if (n >= len)
    {
        temp._nbr = "0";
    }
    else
        temp._nbr.erase(len - n, n);
    return (temp);
}
bigint& bigint::operator<<=(unsigned int n)
{
    *this = *(this) << n;
    return (*this);
}
bigint& bigint::operator>>=(unsigned int n)
{
    *this = *(this) >> n;
    return (*this);
}


bigint bigint::operator<<(const bigint& other)const
{
    bigint temp = *(this) << _stringToInt(other.GetString());
    return (temp);
}
bigint bigint::operator>>(const bigint& other)const
{
    bigint temp  = *(this) >>  _stringToInt(other.GetString());
    return (temp);
}
bigint& bigint::operator<<=(const bigint& other)
{
    *this = *(this) << other;
    return (*this); 
}

bigint& bigint::operator>>=(const bigint& other)
{
    *this = *(this) >> other;
    return (*this);
}

		
bool bigint::operator==(const bigint& other) const
{
    return (this->_nbr == other._nbr);
}

bool bigint::operator!=(const bigint& other) const
{
    return (!(this->_nbr == other._nbr));
}

bool bigint::operator<(const bigint& other) const
{
    if (_nbr.length() != other._nbr.length())
        return _nbr.length() < other._nbr.length();
    return _nbr < other._nbr;
}

bool bigint::operator>(const bigint& other) const
{
    return (!(*this < other));
}

bool bigint::operator<=(const bigint& other) const
{
     return ((*this < other) || *this == other);
}

bool bigint::operator>=(const bigint& other) const
{
 return ((*this > other) || *this == other);
}
std::ostream & operator << (std::ostream & os, const bigint &other)
{
    os << other.GetString();
    return (os);
}

bigint::~bigint(){}