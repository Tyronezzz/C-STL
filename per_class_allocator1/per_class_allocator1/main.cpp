//
//  main.cpp
//  per_class_allocator1
//
//  Created by Tyrone Hou on 11/9/20.
//  Copyright © 2020 Tyrone Hou. All rights reserved.
//

#include <iostream>
using namespace std;

class Screen{
  
    public:
        Screen(long x) : i(x){}
        ~Screen() {}
        int get() {return i;}
        static Screen* getFreeStore(){return freeStore;}
    
        static void* operator new(size_t);
        static void operator delete(void*, size_t);
    
    private:
        Screen* next;
        static Screen* freeStore;    // first free block
        static const int screenChunk;
        long i;
    
};

class Screen2{
    
public:
    Screen2(long x) : i(x){}
    ~Screen2() {}
    int get() {return i;}
    
//    static void* operator new(size_t);
//    static void operator delete(void*, size_t);
    
private:
    Screen2 * next;
    static Screen2* freeStore;    // first free block
    static const int screenChunk;
    long i;
    
};



Screen* Screen::freeStore = 0;  //最开始的头结点
const int Screen::screenChunk = 24;



void *Screen::operator new(size_t size) {  //size为元素大小,一次分配24个
    
    Screen *p;
    if(!freeStore)
    {
        size_t chunk = screenChunk* size;
        freeStore = p = reinterpret_cast<Screen*>(new char[chunk]);
        
        for(; p != &freeStore[screenChunk - 1]; ++p) {   // cut the memory
            p->next =  p + 1;
        }
        p->next = 0;
    }

    p = freeStore;
    freeStore = freeStore->next;
    return p;
}


// 将deleted object 插回到free list前端
// e.g.   1 -> 2 -> 3 -> F' -> F
//        deleting...
//        2->3->F'   (1)F -> F' -> F

void Screen::operator delete(void* p, size_t) {
    
    (static_cast<Screen*>(p))->next = freeStore;
    freeStore = static_cast<Screen*>(p);
    cout<<"deleting "<<p<<endl;
}



//测试重载operator new，分配内存不带cookie
void TEST_WITHOUT_COOKIE(){
    
    cout << endl << "TEST_WITHOUT_COOKIE" << endl;
    cout << "size of Screen: " << sizeof(Screen)  << endl;
    
    int const N = 24;
    Screen* p[N];
    for(int i = 0; i < N; i ++) {
        p[i] = new Screen(i);
    }
    
    for(int i =0 ; i < 10; i ++) {
        cout << p[i] << endl;
    }
    
    for(int i = 0;i < N; i ++){
        delete p[i];
    }
    
    cout<<"Finally, the freeStore is "<<Screen::getFreeStore()<<endl;
    return;
}


void TEST_WITH_COOKIE(){
    
    cout << endl << "TEST_WITH_COOKIE" << endl;
    cout << "size of Screen2: " << sizeof(Screen2)  << endl;
    
    int const N = 100;
    Screen2* p[N];
    for(int i = 0; i < N; i ++) {
        p[i] = new Screen2(i);
    }
    
    for(int i =0 ; i < 10; i ++) {
        cout << p[i] << endl;
    }
    
    for(int i = 0;i < N; i ++){
        delete p[i];
    }
    return;
}


int main(int argc, const char * argv[]) {
    
    TEST_WITHOUT_COOKIE();
    TEST_WITH_COOKIE();
    return 0;
}
