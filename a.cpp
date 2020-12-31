#include<iostream>
#include<cfloat>
#include<string>
#include<cstring>

struct person
{
    std::string name{"Haymax"};
    int age=18;
};
int sum_arr(int *begin, int *end);
int sum(int (*arr)[4], int size);

int main()
{
    person candidate0;
    char hello_string[50] = "hello world";
    std::cout << candidate0.name << std::endl;
    std::cout << strlen(hello_string) << std::endl;

    int my_array[10];
    std::cout << my_array << std::endl;

    const int n_arr = 5;
    int cookies[n_arr] = {1, 2, 3, 4, 5};
    std::cout << sum_arr(cookies, cookies+n_arr) << std::endl; 

    int data[3][4] = {
        {1, 2, 3, 4}, 
        {2, 3, 4, 5}, 
        {3, 4, 5, 6}
    };
    std::cout << sum(data, 3) << std::endl;
}

int sum_arr(int *begin, int *end) {
    int *ptr;
    int sum=0;
    
    for (ptr=begin; ptr!=end; ptr++){
        sum += *ptr;
    }

    return sum;
}

int sum(int (*arr)[4], int size){
    int total = 0;
    for (int i=0; i<size; i++){
        for (int j=0; j<4; j++){
            total += arr[i][j];
        }
    }
    return total;
}





