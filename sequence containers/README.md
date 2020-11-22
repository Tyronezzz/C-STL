# **jjhou, yyds!**

## Reference 
- https://www.bilibili.com/video/BV1Kb411B7N8?p=12
- https://www.bilibili.com/video/BV1db411q7B8?p=15
- https://github.com/haotianmichael/Algorithm/blob/master/C%2B%2B/docs/MemoryManagement.md
- STL源码剖析



## vector
```
    class vector{
        protected:
            iterator start;       // 目前使用空间的头
            iterator finish;      // 目前使用空间的尾(+1)
            iterator end_of_storage;   // 目前可用空间的头(+1)
        ...
    };
```

- GNU2.9   iterator traits  ->  T*
- G4.9 iterator traits  ->  vector<T>::iterator
