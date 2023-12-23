#include<iostream>
using namespace std;

class node{
public:
    char c;
    int f;
    node* left;
    node* right;
    node():left(nullptr),right(nullptr){c='\0';}
    node(int x): f(x), left(nullptr),right(nullptr){c='\0';}
    node(char a, int b): c(a), f(b), left(nullptr),right(nullptr){}
    node(char a, int b, node* n1, node* n2){
        c=a;
        f=b;
        left=n1;
        right=n2;
    }
    bool operator>(const node& other) const {
        return f > other.f;
    }
};