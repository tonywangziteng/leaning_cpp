#include<iostream>
#include<cfloat>
#include<string>
#include<cstring>


struct Node{
    int value;
    Node *next;
    Node *father;
    // 构造函数，构造node的时候被调用，大括号不能省略
    Node():value(1), next(nullptr), father(nullptr){};
    // 默认构造函数和构造函数重载；
    Node(int v, Node *next_){
        std::cout<<"v is "<<v<<std::endl;
        value = v;
        father = new Node;
        next = next_;
    };
    ~Node(){
        std::cout<<"deleting"<<std::endl;
        delete father, next;
    };
};

int main(){

    Node a;
    Node *b = new Node;
    Node c(5, b);
    return 0;
}



