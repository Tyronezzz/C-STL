//
//  main.cpp
//  static_allocator3
//
//  Created by Tyrone Hou on 11/9/20.
//  Copyright © 2020 Tyrone Hou. All rights reserved.
//

#include <iostream>
#include <complex>

using namespace std;



class my_allocator{
    private:
        struct obj{
             struct obj* next;  //Embedded pointer
        };
    public:
        my_allocator() {}
        ~my_allocator() {}
    
    public:
        void* allocate(size_t);
        void deallocate(void*, size_t);
    
    private:
        obj* freeStore = nullptr;
        const int CHUNK = 5;      // chunk内连续，chunk间可能不连续
};


void* my_allocator::allocate(size_t size) {
    obj* p;
    if(!freeStore) {
        freeStore = p = static_cast<obj*>(malloc(CHUNK * size));
        
        //切割
        for(int  i = 0; i < (CHUNK - 1); i ++) {
            p->next = (obj*)((char*)p + size);
            p = p->next;
        }
        p->next = nullptr;
    }
    p = freeStore;
    freeStore = freeStore->next;
    return p;
}



void my_allocator::deallocate(void* p, size_t) {
    
    (static_cast<obj*>(p))->next = freeStore;
    freeStore = static_cast<obj*>(p);
}


class Foo{
public:
    long L;
    string str;
    static my_allocator myAlloc;
    
public:
    Foo(long l) : L(l) {}
    static void* operator new(size_t size) {
        return myAlloc.allocate(size);
    }
    static void operator delete(void* dead, size_t size) {
        return myAlloc.deallocate(dead, size);
    }
};
my_allocator Foo::myAlloc;



class Goo{
public:
    complex<double> c;
    string str;
    static my_allocator myAlloc;
public:
    Goo(const complex<double>& x) : c(x) {}
    static void* operator new(size_t size) {
        return myAlloc.allocate(size);
    }
    
    static void operator delete(void* pdead, size_t size) {
        return myAlloc.deallocate(pdead, size);
    }
};
my_allocator Goo::myAlloc;




int main(int argc, const char * argv[]) {
   
    cout << "sizeof(my_allocator)" << sizeof(my_allocator)  << endl;  //16字节
    Foo* p[100];
    cout << "sizeof(Foo): " << sizeof(Foo) << endl;
    
    
    for(int i =0 ;i  < 10; i ++) {
        p[i] = new Foo(i);
        cout << p[i] << ' ' << p[i]->L << endl;
    }
    
    
    for(int i =0 ; i < 10; i ++) {
        delete p[i];
    }
    
    
    Goo *Gp[100];
    cout << "sizeof(Goo): " << sizeof(Goo) << endl;
    for(int i = 0; i < 10; i ++) {
        Gp[i] = new Goo(complex<double>(i, i + 1));
        cout << Gp[i] << ' '<< Gp[i]->c << endl;
    }
    
    for(int i = 0; i < 10; i ++) {
        delete p[i];
    }

    
    return 0;
}
