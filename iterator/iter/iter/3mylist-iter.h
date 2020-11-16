//
//  3mylist-iter.h
//  iter
//
//  Created by Tyrone Hou on 11/15/20.
//  Copyright © 2020 Tyrone Hou. All rights reserved.
//

#ifndef _mylist_iter_h
#define _mylist_iter_h

#include "3mylist.h"

template <class Item>
struct ListIter{

    Item *ptr;
    
    ListIter(Item *p = 0) : ptr(p) {}
    
    //缺省copy ctor, operator =
    
    Item& operator*() const {return *ptr;}
    Item* operator->() const {return ptr;}
    
    // pre increment
    ListIter& operator++()
    {
        ptr = ptr->next();
        return *this;
    }
    
    // post increment
    ListIter operator++(int)
    {
        ListIter tmp = *this;
        ++*this;
        return tmp;
    }
    
    
    bool operator==(const ListIter& i) const
    {return ptr == i.ptr; }
    
    bool operator!=(const ListIter& i) const
    {return ptr != i.ptr; }
    
};

#endif /* _mylist_iter_h */
