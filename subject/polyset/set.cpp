#include "set.hpp"


set::set(searchable_bag& other) : _bag(other)
{

}

bool set::has(int value) const
{
	return(_bag.has(value));
}

void set::insert (int value)
{
	if(!(this->has(value)))
		_bag.insert(value);
}

void set::insert (int *data, int size)
{
	for(int i = 0; i < size; i++)
	{
		this->insert(data[i]);
	}
}

void set::print() const
{
	_bag.print();
}

void set::clear()
{
	_bag.clear();
}

const searchable_bag& set::get_bag()
{
	return(this->_bag);
}


set::~set()
{

}

