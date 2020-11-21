//
//  main.cpp
//  vector
//
//  Created by Tyrone Hou on 11/20/20.
//  Copyright © 2020 Tyrone Hou. All rights reserved.
//

#include <iostream>
#include <memory>
#include <new>

using namespace std;

//namespace ty_vector {
//    template <class T>
//    class vector {
//
//    public:
//        typedef T value_type;
//        typedef value_type* pointer;
//        typedef value_type* iterator;
//        typedef value_type& reference;
//        typedef size_t size_type;
//        typedef ptrdiff_t difference_type;
//
//
//    protected:
//        //typedef simple_alloc<value_type> data_allocator;
//        iterator start;
//        iterator finish;
//        iterator end_of_storage;
//
//        void insert_aux(iterator position, const T& value);
//        //...
//
//    public:
//        iterator begin(){return start;}
//        iterator end(){return finish;}
//
//        //....
//
//
//        void push_back(const T& x);
//
//    };
//
//
//    template <class T>
//    void vector<T>::insert_aux(iterator position, const T& value)
//    {
//        ;
//    }
//
//
//    template <class T>
//    void vector<T>::push_back(const T& x)
//    {
//        if(finish == end_of_storage)
//            insert_aux(end(), x);
//
//        else
//        {
//            allocator<T>::construct(finish, x);
//            ++finish;
//        }
//    }
//
//}



int main(int argc, const char * argv[]) {
//    ty_vector::vector<int> vec;
    
//    vec.push_back(1);
    
    
    int x = 6;
    
    cout<<hex<<(x&-x)<<endl;
    
    
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
