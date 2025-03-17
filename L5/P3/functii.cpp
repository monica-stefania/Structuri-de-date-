#include <iostream>
#include "header.h"
#include <string.h>
using namespace std;

void init(Stiva *&s){
    s=0;
}
void push(Stiva*&s, int val){
    Stiva *p=new Stiva;
    p->data=val;
    p->next=s;
    s=p;
}
void pop(Stiva*&s){
    Stiva*p=s;
    if(!isEmpty(s)){
        s=s->next;
        delete p;
    }
    else 
    {
        s=0;
        delete p;
        return;
    }
}
int top(Stiva*s){
    if(!isEmpty(s))
         return s->data;
    return 0;
}
bool isEmpty(Stiva *s){
    if(s==0)
        return true;
    return false;
}
bool Operand(char c){
    if(c>='0' && c<='9')
        return true;
    return false;
}
bool Operator(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/')
        return true;
    return false;
}