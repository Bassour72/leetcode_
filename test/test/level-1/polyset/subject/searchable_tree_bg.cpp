#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &other):tree_bag(other)
{

}

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag & other)
{
    if (this != &other)
        tree_bag::operator=(other);
    return (*this);
}

searchable_tree_bag::searchable_tree_bag(/* args */):tree_bag()
{
}

searchable_tree_bag::~searchable_tree_bag()
{
}

bool searchable_tree_bag::_search(tree_bag::node *root, int item) const
{
    if (root == NULL)
        return (false);
    if (root->value == item)
        return (true);
    if (item < root->value)
        return (_search(root->l, item));
    else
       return( _search(root->r, item));
}

bool searchable_tree_bag::has(int item) const
{
    return (_search(tree, item));
}