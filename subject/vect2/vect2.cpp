#include "vect2.hpp"

vect2::vect2()
{
    vec.push_back(0);
    vec.push_back(0);
}

vect2::vect2(int x, int y)
{
    vec.push_back(x);
    vec.push_back(y);

}
vect2::vect2(const vect2 &other)
{
    if (this == &other)
        return;
    vec = other.vec;
}

vect2 &vect2::operator=(const vect2 &other)
{
    if (this == &other)
        return (*this);
    vec = other.vec;
    return (*this);
}

vect2 vect2::operator+(const vect2 &other) const
{
    vect2 temp;
    temp.vec[0] = vec[0] + other.vec[0];
    temp.vec[1] = vec[1] + other.vec[1];
    return (temp);
}

vect2 vect2::operator-(const vect2 &other)const
{
    vect2 temp;
    temp.vec[0] = vec[0] - other.vec[0];
    temp.vec[1] = vec[1] - other.vec[1];
    return (temp);
}

vect2 vect2::operator-()
{
    int x = vec[0]; 
    int y = vec[1];

    return vect2(-x, -y);
}

vect2 &vect2::operator+=(const vect2 &other)
{
    *this = *this + other;
    return (*this);
}

vect2 &vect2::operator-=(const vect2 &other)
{
     *this = *this - other;
    return (*this);
}

vect2 vect2::operator*(int nbr)const
{
    vect2 temp;
    temp.vec[0] = vec[0] * nbr;
    temp.vec[1] = vec[1] * nbr;
    return (temp);
}

vect2 &vect2::operator*=(int nbr)
{
    vec[0] = vec[0] * nbr;
    vec[1] = vec[1] *  nbr;
    return (*this);
}
vect2 vect2::operator*(const vect2 &other) const
{
    vect2 temp;
    temp.vec[0] = vec[0] * other.vec[0];
    temp.vec[1] = vec[1] * other.vec[1];
    return (temp);
}


int  &vect2::operator[](int index)
{
    // if (index < 0 || index > 1)
    //     return (-1);
    return (vec[index]);
}
int  vect2::operator[](int index) const
{
    if (index < 0 || index > 1)
        return (-1);
    return (vec[index]);
}

vect2 vect2::operator++()
{
    
    vec[0] = vec[0] + 1;
    vec[1] = vec[1] + 1;
    return (*this);
}
vect2 vect2::operator++(int)
{
    vect2 temp;
    temp.vec[0] = vec[0];
    temp.vec[1] = vec[1];
    vec[0] = vec[0] + 1;
    vec[1] = vec[1] + 1;
    return (temp);
}


vect2 vect2::operator--()
{
    vec[0] = vec[0] - 1;
    vec[1] = vec[1] - 1;
    return (*this);
   
}

vect2 vect2::operator--(int)
{
   vect2 temp;
    temp.vec[0] = vec[0];
    temp.vec[1] = vec[1];
    vec[0] = vec[0] - 1;
    vec[1] = vec[1] - 1;
    return (temp);
}


bool vect2::operator==(const vect2 &other)const
{

    return (vec[0] == other.vec[0] && vec[1] == other.vec[1]);
}
bool vect2::operator!=(const vect2 &other)const
{
    return (!this->operator==(other));
}
std::ostream &operator<<(std::ostream &os ,const vect2 &other)
{
    os << other[0]<< " " << other[1]; 
    return (os);
}

vect2 operator*(int nbr, const vect2 &other)
{
    
    int x = nbr * other[0];
    int y = nbr * other[1];
    vect2 temp(x,y);
    return (temp);
}
vect2::~vect2(){}     