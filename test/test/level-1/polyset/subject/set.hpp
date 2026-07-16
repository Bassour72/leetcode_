#pragma once

#include "searchable_bag.hpp"

class set
{
private:
    searchable_bag & _bag;
public:
    set(const set &);
    set(searchable_bag &);
    set &operator=(const set &);
    void insert (int);
	void insert (int *, int);
	void print() const;
	void clear();
    bool has(int) const;
   const searchable_bag  &get_bag() const;
    ~set();
};
