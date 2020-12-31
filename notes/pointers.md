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

## 指针常量和常量指针

### 指针常量——指针类型的常量

```cpp
int *const a;
```

代表的是变量 `a` 是一个常量，`a` 的类型是一个 `int指针`。也就是说 `a` 的值（它指向的地址）是不可以进行更改的，但是该地址存储的值是可以更改的。

```cpp
int *const a;
int *b = new int;
*a = 10; //合法
a = b; //非法
```

### 常量指针——指向常量的指针

```cpp
const int *a; 
int const *a;
```

常量指针说的是，该指针变量指向的是一个常量。也就是说，指针所指向的地址是可以改变的，但是地址中的值是常量不可改变。常用于函数参数传递，尤其是数组。

```cpp
int sum_arr(const int *begin, const int *end);
int sum_arr(const int *begin, const int *end) {
    const int *ptr;
    int sum=0;
    
    for (ptr=begin; ptr!=end; ptr++){
        sum += *ptr;
    }

    return sum;
}

int cookies[5] = {1, 2, 3, 4, 5};
int all_cookies = sum_arr(cookies, cookies+5);
```
在上述代码中，传入的函数中的值是不可更改的常量。也即对 `*ptr` 进行赋值是非法的。  

代码中，声明 `ptr` 的时候的 `const` 关键字是必须的，因为在定义函数的时候，用的是 `const int *begin`，必须对应。否则在 `ptr=begin` 的赋值操作会报错。

总结：  
事实上，可以将普通变量的地址给到 const 指针，只不过此时，对于该指针而言，它指向的地址中的值是不可更改的。也可以将 const 变量的地址给 const 指针。  
但是，将 const 变量的地址给普通指针是不可行的，在编译的时候会报错，比如下面的例子：
```cpp 
const int a = 0;
int *ptr = &a; // 非法
```

### 二维数组传参

```cpp 
int data[3][4] = {
    {1, 2, 3, 4}, 
    {2, 3, 4, 5}, 
    {3, 4, 5, 6}
};

// 正确的函数原型
int sum(int arr[][4], int size);
int sum(int (*arr)[4], int size);
// data的本质是 3个[(指向4个int组成的数组)的指针]的数组

// 另一种声明二维数组的方式，数组的指针
char *a[5] = {
    "abc", "aeg", "aeg"
}；

int sum(char **arr, int size);
```
