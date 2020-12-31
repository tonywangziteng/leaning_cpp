#include<iostream>
#include<cfloat>
#include<string>
#include<cstring>

struct person
{
    std::string name{"Haymax"};
    int age=18;
};

int main()
{
    person candidate0;
    char hello_string[50] = "hello world";
    std::cout << candidate0.name << std::endl;
    std::cout << strlen(hello_string) << std::endl;

    int my_array[10];
    std::cout << my_array << std::endl;

    return 0;
}
