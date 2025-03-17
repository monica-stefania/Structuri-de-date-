#include <iostream>
#include "header.h"
using namespace std;
void init(Stiva &s){
    s.vf=-1;
}
void push(Stiva &s, int val){
    s.vf++;
    s.v[s.vf]=val;
}

int pop(Stiva &s){
    return s.v[s.vf--];
}

int top(Stiva s){
    return s.v[s.vf];
}
bool isEmpty(Stiva s){
    if(s.vf==-1)
        return true;
    return false;
}
bool isFull(Stiva s){
    if(s.vf==DIM_MAX-1)
        return true;
    return false;
}