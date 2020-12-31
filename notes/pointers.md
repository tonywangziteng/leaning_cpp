# Cpp学习笔记 指针

## new & delete

在声明一个新的之神变量的时候，最好需要用 `new` 来分配一块合适的内存，并且在使用结束之后用 `delete` 进行删除。在cpp中，对自定义的数据类型使用 `new` 和 `delete`，会分别调用解析函数和析构函数。  
应当尽量避免未分配内存直接声明指针变量

```cpp
// 声明和释放指针变量
int* a_pt = new int;
delete a_pt;
```

### 动态数组
```cpp
// 用new创建动态数组
int* psome = new int [10];
delete [] psome;
```
动态数组的使用方式，其实基本等同于正常的数组
```cpp
*psome; // 数组的第一个元素
psome[i];   //数组的第i个元素
// 指针允许进行加减操作，对应的是移动相应的变量类型位置
psome += 1; // 此时psome指向数组中第一个元素的位置
```
！注， 对于一般的数组声明，其变量名(`my_array`)也等价于 `&my_array[0]`。但是数组的便俩革命不允许进行加减操作
```cpp
int my_array[10]={0};
std::cout << my_array << std::endl;
// 0x61fd70
my_array + 1; // not valid
```

## 指向对象（结构体）的指针

该类指针指向对象的首地址，引用该类内部成员的话，使用 `->` 运算符。
```cpp
struct person
{
    std::string name{"Haymax"};
    int age=18;
};

person *me = new person {"Haymax", 21};
std::cout << me->age;
std::cout << (*me).age;
delete me;
```

## 数组的动态联编和静态联编

在声明的时候，使用形如 `int array[10] {0};` 进行定义的数组使用的是静态联编，在编译的时候就分配了内存。而使用 `int *array = new int [10]`，是在运行过程中动态进行内存分配和回收的，因此必须加上 `delete` 释放内存。

