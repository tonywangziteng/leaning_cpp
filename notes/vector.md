# Cpp学习笔记 vector，array 模板类

## vector

vector类似string，是一种动态数组。可以在运行的阶段动态地创建数组，分配内存，也可以在末尾添加数据，在中间插入数据。  

！使用vector需要包含标准头文件 `#include <vector>`，vector类在名称空间 `std` 中。  

`vector` 功能十分强大，但是其效率稍低。如果需要使用的是长度固定的数组，使用数组是更好的选择。

### vector的声明和使用

```cpp 
#include <vector>

//声明 vector<typeName> vtName(n_elem);
std::vector<double> my_vec(10);

//vector 类似指针，不检查越界，但是可以使用 at 方法防止越界
my_vec[-1]; // 不报错，但是很危险。相当于 *(my_vec-1)
my_vec.at(-1); // invalid syntax
```

## array 

- **长度固定**，静态存储
- 需要 `#include <array>`，在名称空间 `std` 中。

### array的声明和使用

```cpp
#include <array>

//声明 array<typeName, n_elem> arName;
std::array<double, 5> my_array;

//不检查越界，可以使用成员函数at()
my_array.at(-2); // invalid syntax
```

## 数组，array, vector

- 数组复制的时候必须逐个元素赋值，但是array,vector都可以直接赋值。
