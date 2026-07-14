#ifndef SEARCHABLE_TREE_BAG_HPP
#define SEARCHABLE_TREE_BAG_HPP

#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class searchable_tree_bag: virtual public tree_bag, virtual public searchable_bag 
{
private:
    /* data */
public:
    searchable_tree_bag(/* args */);
    searchable_tree_bag(const searchable_tree_bag &other);
    searchable_tree_bag &operator=(const searchable_tree_bag &other);
    bool has(int item) const;
    ~searchable_tree_bag();
};




#endif