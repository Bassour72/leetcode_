#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

using namespace std;
class Box
{
private:
	int _length;
	int _breadth;
	int _height;
public:
	Box(/* args */);
	Box(int length, int breadth, int height);
	Box( const Box &other);
	int getLength(void) const;
	int getBreadth(void) const;
	int getHeight(void) const;
	Box &operator =(const Box &other);
	bool operator <(const Box &other);
	bool operator >(const Box &other);
	bool operator ==(const Box &other);
	long long CalculateVolume(void);
	~Box();
};
ostream &operator <<(const ostream &os, const Box &other);

Box::Box(/* args */):_length(0), _breadth(0), _height(0)
{
}
Box::Box(int length, int breadth, int height)
{
	_length = length;
	_breadth = breadth;
	_height = height;
}
Box::Box(const Box &other)
{
	_length = other._length;
	_breadth = other._breadth;
	_height = other._height;
}

int Box::getLength(void) const
{
	return (_length);
}
int Box::getBreadth(void) const
{
	return (_breadth);
}
int Box::getHeight(void) const
{
	return (_height);
}

long long Box::CalculateVolume()
{
    return static_cast<long long>(getLength()) *
           getBreadth() *
           getHeight();
}

Box &Box::operator =(const Box &other)
{
	_length = other._length;
	_breadth = other._breadth;
	_height = other._height;
	return *this;
}
bool Box::operator<(const Box &other)
{
    if (_length < other._length)
        return true;
    if (_length == other._length && _breadth < other._breadth)
        return true;
    if (_length == other._length && _breadth == other._breadth && _height < other._height)
        return true;
    return false;
}

bool Box::operator ==(const Box &other)
{
	return (this->_length == other._length && this->_height == other._height && this->_breadth == other._breadth);
}
ostream &operator <<(ostream &os, const Box &other)
{

	os << other.getLength() << " " << other.getBreadth() << " " << other.getHeight();
	return os;
}
Box::~Box()
{
}
//std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

class boxClass
{
private:
	int i;
public:
	int get()
	{ int ii = -11111110;
	return ii; }
	boxClass(/* args */);
	~boxClass();
};

boxClass::boxClass(/* args */):i(10)
{
}

boxClass::~boxClass()
{
}

int main()
{	const boxClass c1;
	std::cout << c1.get();

	std::io
	//check2();
}