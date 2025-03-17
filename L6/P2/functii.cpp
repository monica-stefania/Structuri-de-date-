#include <iostream>
#include "header.h"

using namespace std;
void init(Queue &q){
    q.head=0;
    q.tail=0;
}
void put(Queue &q, int val){
    Nod*p=new Nod;
    p->data=val;
    if(isEmpty(q))
    {
        q.tail=p;
        q.head=p;
    }
    else{
        q.tail->next=p;
        q.tail=p;
    }
}
int get(Queue &q){ //verific in main daca coada are minim un element inainte de a apela
    Nod*p=new Nod;
    int a;
    p=q.head;
    a=q.head->data;
    if(q.tail==q.head)//am doar un element
    {
        q.head=0;
        q.tail=0;
        delete p;
    }
    else 
    {
        q.head=q.head->next;
        delete p;
    }
    return a;

}
int front(Queue &q){
    return q.head->data;
}
bool isEmpty(Queue &q){
    if(q.tail==0 && q.head==0)
        return true;
    return false;
}