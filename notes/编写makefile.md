# Cpp学习笔记 编写makefile

## 基本结构
```makefile
目标:依赖  
    命令 #这个前面必须是tab
```

```makefile
OBJS=main.o stock.o
main: $(OBJS)
	g++ -o test $(OBJS)
main.o:main.cpp 
	g++ -c main.cpp
stock.o: .\utils\stock.cpp 
	g++ -c .\utils\stock.cpp
```

## 使用变量 和 通配符

$<：第一个依赖文件；  
$@：目标；  
$^：所有不重复的依赖文件，以空格分开​  

wildcard：
扩展通配符，搜索指定文件。在此我们使用src = $(wildcard ./utils/*.c)，代表在当前目录下搜索所有的.c文件，并赋值给src。函数执行结束后，src的值为：main.c fun1.c fun2.c。

patsubst：
替换通配符，按指定规则做替换。在此我们使用

```makefile
obj = main.o stock.o  
target = app  
CC = g++  

$(target): $(obj)  
    $(CC) $(obj) -o $(target)  

%.o: %.c  
    $(CC) -c $< -o $@  
```
