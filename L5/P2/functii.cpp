#include <iostream>
#include "header.h"
using namespace std;

void init(Stiva*&s){
    s=0;
}
void push(Stiva*&s, int val){
    Stiva*p=new Stiva;
    p->data=val;
    p->next=s;
    s=p;
}
int pop(Stiva*&s){
    Stiva *p=s;
    if(!isEmpty(s))
    {
        int val=s->data;
        s=s->next;
        delete p;
        return val;
    }
    else 
        return 0;
        
}
int top(Stiva *s){
    return s->data;
}
bool isEmpty(Stiva *s){
    if(s==0)
        return true;
    else 
        return false;
}
