//
//  main.cpp
//  per_class_allocator2
//
//  Created by Tyrone Hou on 11/9/20.
//  Copyright © 2020 Tyrone Hou. All rights reserved.
//
// 对象本身的数据内存和 next 指针的数据内存不会同时被使用
// reference https://blog.csdn.net/ZLP_CSDN/article/details/105776484

/*
 类的内存分配器精简版本
 优点: next指针变成Embedded Pointer
 缺点: 内存池最终delete后并没有还给OS ,并没有调用free(不是内存泄漏)
 */

#include <iostream>
#include <vector>
using namespace std;


class Airplane
{
    public:
        Airplane (){}
        ~Airplane (){}
    
    private:
        struct AirplaneRep{
            unsigned long miles;  // 8 bytes
            char type;  // 1 byte
        };
    
    private:
        // we only use next when allocating or deallocating the memory,
        // so it's smart to use the embedded pointer
        union {  //16bytes Embedded Pointer
            AirplaneRep rep;
            Airplane* next;
        };
    public:
        unsigned long getMiles() {return rep.miles;}
        char getType() {return rep.type;}
        void set(unsigned long m, char t) {
            rep.miles = m;
            rep.type = t;
        }
    public:
        static void* operator new(size_t size);
        static void operator delete(void* deadObj, size_t size);
    private:
        static const int BLOCK_SIZE;
        static Airplane* headOfFreeList;
};
Airplane* Airplane::headOfFreeList;
const int Airplane::BLOCK_SIZE = 512;



void* Airplane::operator new(size_t size) {
    
    if(size != sizeof(Airplane)) {  //继承发生就会有问题
        return ::operator new(size);
    }
    
    Airplane* p = headOfFreeList;
    if(p){
        headOfFreeList = p->next;
    }else{
        Airplane* newBlock = static_cast<Airplane*>(::operator new(BLOCK_SIZE * sizeof(Airplane)));
        
        for(int i = 1; i < BLOCK_SIZE - 1; i ++)
            newBlock[i].next = &newBlock[i+1];
        
        newBlock[BLOCK_SIZE - 1].next = 0;
        p = newBlock;
        headOfFreeList = &newBlock[1];
    }
    return p;
}

//重载
void Airplane::operator delete(void* deadObj, size_t size) {
    
    if(!deadObj) return;
    if(size != sizeof(Airplane)) {  //继承情况
        ::operator delete(deadObj);
        return;
    }
    
    Airplane* carcass = static_cast<Airplane*>(deadObj);
    carcass->next = headOfFreeList;
    headOfFreeList = carcass;
}



int main(int argc, const char * argv[]) {
    
    size_t const N = 10;
    Airplane* p[N];
    
    for(size_t i = 0; i < N; i ++) {
        p[i] = new Airplane;           // :: new
    }
    
    p[1]->set(1000, 'A');
    p[2]->set(2000, 'B');
    p[3]->set(3000, 'C');
    
    for(int i = 0; i < 10; i ++) {
        cout << p[i] << endl;
    }
    
    for(size_t i = 0; i < N; i ++) {
        delete p[i];
    }
    
    
    return 0;
}
