#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class set
{
private:
    searchable_bag &_bag;
public:
    // set();
    set(searchable_bag & other);
    void insert (int);
	void insert (int *, int);
	void print() const;
	void clear();
    const searchable_bag &get_bag();
    bool has(int) const;
    ~set();
    
};
/*

*/
#endif //