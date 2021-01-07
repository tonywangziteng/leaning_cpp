#include<iostream>
#include<cfloat>
#include<string>
#include<cstring>

struct job{
    std::string name;
    int salary;
};

template <typename T>
void Swap(T &, T &);

template<> void Swap<job>(job &, job &);

// void Swap(job &, job &);

int main(){
    job good_job = {"mechmind", 250};
    job bad_job = {"ByteDance", 400};

    Swap(good_job, bad_job);
    std::cout << good_job.name << std::endl;
    std::cout << good_job.salary;
}

template <typename T>
void Swap(T &a, T &b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}
/*
void Swap(job &a, job &b){
    int temp;
    temp = a.salary;
    a.salary = b.salary;
    b.salary = temp;
}*/

template<> void Swap<job>(job &a, job &b){
    std::string temp;
    temp = a.name;
    a.name = b.name;
    b.name = temp;
}

