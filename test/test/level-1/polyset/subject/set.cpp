#include "set.hpp"


set::set(const set &other):_bag(other._bag)
{

}

set &set::operator=(const set &other)
{
    if (this != &other)
        this->_bag = other._bag;
   return (*this); 
}

void set::insert (int item)
{
    // std::cout << "hh\n";

    if (!_bag.has(item))
        _bag.insert(item);
}
void set::insert (int *data, int count)
{
    //  if (has(item))
    //     return ;
    _bag.insert(data, count);
}
void set::print() const
{
    _bag.print();   
}
void set::clear()
{
    _bag.clear();
}
bool set::has(int item) const
{
   return (_bag.has(item)); 
}

set::set(searchable_bag & other):_bag(other)
{

}
const searchable_bag  &set::get_bag() const
{
    return(_bag);
}
set::~set()
{
}
