
#ifndef SEARCHABLE_ARRAY_BAG_HPP
#define SEARCHABLE_ARRAY_BAG_HPP

#include <iostream>
#include "array_bag.hpp"
#include "searchable_bag.hpp"
class searchable_array_bag: public array_bag, public searchable_bag 
{
private:
    /* data members */

public:
    searchable_array_bag();
    searchable_array_bag(const searchable_array_bag& other);
    // Searchable_array_bag(/* parameters here */);
    searchable_array_bag& operator=(const searchable_array_bag& other);
    ~searchable_array_bag();
    bool has(int) const;
};

#endif // SEARCHABLE_ARRAY_BAG_H