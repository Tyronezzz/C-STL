

Here are the notes of STL memory management.

##**jjhou, yyds!**

## Reference
- https://www.bilibili.com/video/BV1Kb411B7N8?p=12
- https://github.com/haotianmichael/Algorithm/blob/master/C%2B%2B/docs/MemoryManagement.md
- STL源码剖析



## Allocator
### Prerequisites
- some files
- per_class_allocator1
- per_class_allocator2
- static_allocator3
- macro_allocator4

- embedded pointer
```
union obj{
union obj* next;
char client_data[1];
}
```
We only use _next_ when allocating or deallocating the memory, so it's smart to use the embedded pointer.


![image](https://github.com/Tyronezzz/CPP-STL/blob/master/images/alloc1.png)


### Two allocators
SGI offers two allocators, _malloc_alloc_template and _default_alloc_template.

![image](https://github.com/Tyronezzz/CPP-STL/blob/master/images/alloc2.png)


Here is the freelist.

![image](https://github.com/Tyronezzz/CPP-STL/blob/master/images/alloc3.png)

For every block in freelist, it allocates 20 * 2 * blocksize(e.g, 32) when initialization. 20 for use and 20 for memory pool.




