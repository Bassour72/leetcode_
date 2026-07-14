#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag(/* args */):tree_bag(), searchable_bag()
{
}

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &other)
{
    if (this == &other)
        return (*this);
    tree_bag::operator=(other);
    return (*this);
}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &other)
:tree_bag(other), searchable_bag(other)
{

}

bool searchable_tree_bag::has(int item) const
{
    node *root = tree;
	while (root != NULL) 
    {
        if (item == root->value)
            return (true);
		if (item < root->value) 
        {
			if (root->l != NULL) 
            {
				root = root->l;
			}
            else
                root = root->l;
		} 
        else if (item > root->value) 
        {
			if (root->r != NULL) 
            {
				root = root->r;
			}
            else
                root = root->r;
		} 
	}
    return (false);
   
}
searchable_tree_bag::~searchable_tree_bag()
{
}