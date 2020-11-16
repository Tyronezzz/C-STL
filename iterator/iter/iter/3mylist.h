//
//  3mylist.h
//  iter
//
//  Created by Tyrone Hou on 11/15/20.
//  Copyright © 2020 Tyrone Hou. All rights reserved.
//

#ifndef _mylist_h
#define _mylist_h

#include <iostream>
#include <assert.h>

template <typename T>
class ListItem {
    
public:
    T value() const {return _value;}
    ListItem *next() const {return _next;}
    
//private:
    T _value;
    ListItem* _next;
};




template <typename T>
class List {
    
public:
    void insert_front(T value){
        ListItem<T> *tmp = new ListItem<T>();      // ListItem *tmp = new ListItem(value);
        assert(NULL != tmp);
        tmp->_value = value;
        
        if(NULL == _front && NULL == _end)
        {
            _front = _end = tmp;
        }
        
        else
        {
            tmp ->_next = _front;
            _front = tmp;
        }
        
        _size++;
    }
    
    void insert_end(T value){
        
        ListItem<T> *tmp = new ListItem<T>();
        assert(NULL != tmp);
        tmp->_value = value;
        
        if(NULL == _front && NULL == _end)
        {
            
            _front = _end = tmp;
        }
        
        else
        {
            _end ->_next = tmp;
            _end = tmp;
        }
        
        _size++;
        
    }
    
    
    void display(std::ostream &os = std:: cout) const{
        
        ListItem<T> *p = _front;
        while ( NULL != p && p != _end+1 )
        {
            os << p->_value << "   ";
            p = p ->_next;
        }
        os << std::endl;
    }
    
    ListItem<T>* front()
    {
        return _front;
    }
    
    
private:
    ListItem<T>* _front;
    ListItem<T>* _end;
    long _size;
    
};



#endif /* _mylist_h */
