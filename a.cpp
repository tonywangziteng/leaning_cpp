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

    char a[10] = {"Hay"};
    std::string b = {"Haymax"};
    char c[10] = "Hay";

    std::cout << (a==c) << std::endl;
    std::cout << *a << std::endl;

    const char* cities[3] = {
        "aiejga", 
        "oiaweg", 
        "aieoha"
    };
    char* city = new char [10];
    city = "aweg";
    std::cout << city <<std::endl;
    for (int i; i<3; i++){
        std::cout << cities[i] << std::endl;
    }
    return 0;
}
