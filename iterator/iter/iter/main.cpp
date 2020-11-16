//
//  main.cpp
//  iter
//
//  Created by Tyrone Hou on 11/15/20.
//  Copyright © 2020 Tyrone Hou. All rights reserved.
//

#include <iostream>
//#include "3mylist.h"
#include "3mylist-iter.h"

// find()比较时 iter的类型为ListItem<int>, value的类型为int，故不可直接比较
template <typename T>
bool operator!=(const ListItem<T>& item, T n)
{
    return item.value() != n;
}


template <class InputIterator, class T>
InputIterator find(InputIterator first, InputIterator last, const T& value)
{
    while ( first != last && *first != value )
    {
        ++first;
    }
    return first;
}


int main(int argc, const char * argv[]) {

    List<int> mylist;
    
    for(int i=0;i<5;i++)
    {
        mylist.insert_front(i);
        mylist.insert_end(i+2);
    }
    mylist.display();
    
    
    ListIter<ListItem<int>> begin(mylist.front());
    ListIter<ListItem<int>> end;
    ListIter<ListItem<int>> iter;

    iter = find(begin, end, 3);
    if(iter == end)
        std::cout<<"Not found"<<std::endl;
    else
        std::cout<<"Found "<<iter->value()<<std::endl;


    iter = find(begin, end, 7);
    if(iter == end)
        std::cout<<"Not found"<<std::endl;
    else
        std::cout<<"Found "<<iter->value()<<std::endl;

    
    return 0;
}
