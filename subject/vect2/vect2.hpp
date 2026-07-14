#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <vector>
#include <iostream>


class vect2 
{

private:
    std::vector<int> vec;
public:
    vect2();
    vect2(int x, int y);
    vect2(const vect2 &other);
    vect2 &operator=(const vect2 &other);
    
    vect2 operator+(const vect2 &other) const;
    vect2 operator-(const vect2 &other) const;
    vect2 operator-();
    vect2 &operator+=(const vect2 &other);
    vect2 &operator-=(const vect2 &other);
    vect2 &operator*=(int);
    vect2 operator*(const vect2 &other) const;
    int  &operator[](int index);
    int  operator[](int index) const;



    vect2 operator++();
    vect2 operator++(int);

    vect2 operator--();
    vect2 operator--(int);


    bool operator==(const vect2 &other) const;
    bool operator!=(const vect2 &other) const;
    
    vect2 operator*(int)const;

    // vect2 operator+();
    // vect2 operator+();
    // vect2 operator+();
    // vect2 operator+();
    // vect2 operator+();

    ~vect2();     

};

std::ostream &operator<<( std::ostream &os ,const vect2 &other);
vect2 operator*(int, const vect2 &other);


#endif // VECTOR2_HPP