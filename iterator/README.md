# **jjhou, yyds!**

## Reference 
- https://www.bilibili.com/video/BV1Kb411B7N8?p=12
- https://github.com/haotianmichael/Algorithm/blob/master/C%2B%2B/docs/MemoryManagement.md
- STL源码剖析



## Iterator
迭代器是一种 smart pointer

- dereference  (operator *)
- member access   (->)

## associated type
- template 参数推导机制
- 迭代器相应型别不只是“迭代器所指对象的型别”一种而已
- iterator可能退化成pointer -> 萃取机(iterator traits)必须有能力分辨所获得的iterator是 (1)class iterator to T 还是(2) native pointer to T。利用partial specialization可以达到目的。  **中间层思想**

![image](https://github.com/Tyronezzz/CPP-STL/blob/master/iterator/images/interact.png)

 1. value type: 迭代器所指对象的型别
 2. difference type: 两个迭代器之间的距离

