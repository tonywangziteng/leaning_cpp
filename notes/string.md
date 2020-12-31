# Cpp学习笔记 字符串

## C风格字符串

c风格字符串其实就是字符数组，只不过要求该字符数组最后一个是`'\0'`

### 声明

```cpp
char my_string[50];
char my_string[] = "init string";
char my_string[] {"init string"};
``` 
！必须是用数组存储，类似于 `"init string"` 的初始化事实上返回的该字符串的地址。

### 相关操作 

在 `cstring` 这个头文件中，事实上每个函数都是接受的 **字符串的首地址**
- `strlen(str)` ，返回的是字符串的长度。  
- `strcpy(str1, str2)`，把str2的值复制到str1
- `strcat(str1, str2)`，把str2的值拼接到str1之后

！不能将一个C风格的字符串赋值给另一个  


## String类

`string` 类位于 `std::string` 里面，隐藏了字符串的数组属性。  

### 声明：
 
```cpp 
std::string my_string {"init string"};
std::string my_string = "init string";
```
不再需要使用数组来声明

### 相关操作
- 赋值：`str1 = str2;`
- 拼接：`str1 = str2 + str3;`
- 附加：`str1 += str2;`
- 返回长度：`str.size();`

