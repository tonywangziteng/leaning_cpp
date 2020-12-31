# Cpp学习笔记 cin&cout

2020.12.25

## cin的使用
`cin` 的可以自动识别接受输入的变量的类型，并且转换。但是也存在相应的缺点
1. `cin` 会读取空格、回车、tab做为输入的结束，然后将之后的输入留在输入队列中。比如
    ``` c++
    char name[20];
    std::cin >> name;
    ----------
    Donald Trump
    ```
    那么name中存储的将会是Donald
2. `cin` 读取其它类型的变量的时候，会把最后的回车留在输入队列中。因此正确读入的写法如下：
    ``` cpp
    int a=0;
    std::cin >> a;
    std::cin.get(); //std::cin.get()会读入缓冲区中的下一个字符
    ```  
3. `cin.get(chr)` 将下一个字符读入字符变量chr中。

## cin.get() v.s. cin.getline()

`cin.get()` 的其中一种变体是面向行输入的，使用方法和 `cin.getline()` 相似。二者都是从输入中读入一整行的字符串，以换行符为结尾，因此可以读入空格，但是二者有区别。  

```cpp
std::cin.get(my_str, str_len);
std::cin.getline(my_str, str_len);
```

- `cin.get()` 读入一整行的字符串之后，会保留最后结尾处的换行符，在结尾添加`'\0'`
- `cin.getline()` 读入一整行字符串后，会将结尾的换行符自动替换为`'\0'`

## EOF: End Of File

EOF是文件结束的标志，在win中使用 `<ctrl>Z<Enter>` 来从键盘输入中模拟。  

可以使用 `cin.fail()` 来判断是否检测到了 `EOF`，当检测的时候，`cin` 会把标志位有效，然后 `cin.fail()` 会返回 1。之后如果再次调用 `cin` 会失效。  

另外 `cin.get()` 的返回值是一个 `cin` 对象，当它位于一个需要判断的位置的时候，会自动转换为 `bool` 类型。读取成功的话，返回 `true`， 否则 `false`。  

因此可以这样利用EOF标志，来控制循环
```cpp
while (!std::cin.fail()){
    ...
}

while (std::cin.get()){
    ...
}
```
