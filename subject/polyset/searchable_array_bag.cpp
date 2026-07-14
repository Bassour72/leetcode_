#include "searchable_array_bag.hpp"


searchable_array_bag::searchable_array_bag():array_bag(), searchable_bag()
{

}

searchable_array_bag::searchable_array_bag(const searchable_array_bag& other):array_bag(other), searchable_bag(other)
{

}

searchable_array_bag& searchable_array_bag::operator=(const searchable_array_bag& other)
{
    
    if (this == &other)
        return (*this);
    array_bag::operator=(other);
    return (*this);
}

bool searchable_array_bag::has(int item) const
{
    for (size_t i = 0; (int)i < size; i++)
    {
        if (data[i] == item)
            return (true);
    }
    return (false);
}

searchable_array_bag::~searchable_array_bag()
{

}

// void print() const { std::cout << "Class: Searchable_array_bag" << std::endl; }