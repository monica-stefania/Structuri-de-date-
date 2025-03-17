#include <iostream>
#include "header.h"
using namespace std;

void init(Queue &q){
    q.head=q.tail=0;
}
void put(Queue &q, int val){
    if(!isFull(q))
        q.v[q.tail++]=val;
    else 
        cout<<"Coada este plina\n";
}
int get(Queue &q){
    if(!isEmpty(q))
        return q.v[q.head++];
    return 0;
}
int front(Queue &q){
     if(!isEmpty(q))
        return q.v[q.head];
    return 0;
}
bool isEmpty(Queue &q){
    if(q.head==q.tail)
        return true;
    return false;
}
int nextPoz(int index){
    if(index<DIM_MAX-1)
        return index+1;
    return 0;
}
bool isFull(Queue &q){
    if(nextPoz(q.tail)==q.head)
        return true;
    return false;
}