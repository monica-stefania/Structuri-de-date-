#include <iostream>
#include <cstring>
#include "header.h"
using namespace std;

void initS(Stiva *&s)
{
    s = 0;
}
void push(Stiva *&s, int val)
{
    Stiva *p = new Stiva;
    p->data = val;
    p->next = s;
    s = p;
}
int pop(Stiva *&s)
{
    if (!isEmptyS(s))
    {
        Stiva *p;
        p = s;
        int val = p->data;
        s = s->next;
        delete p;
        return val;
    }
    return 0;
}
bool isEmptyS(Stiva *s)
{
    if (s == 0)
        return true;
    return false;
}

void initQ(Queue &q)
{
    q.head = 0;
    q.tail = 0;
}
void put(Queue &q, int val)
{
    Element *p = new Element;
    p->data = val;
    p->next = 0;
    if (isEmptyQ(q))
    {
        q.head = p;
        q.tail = p;
    }
    else
    {
        q.tail->next = p;
        q.tail = p;
    }
}
int get(Queue &q)
{
    Element *p = q.head;
    int val = p->data;
    if (!isEmptyQ(q))
    {
        if (q.head == q.tail)
        {
            q.head = 0;
            q.tail = 0;
            delete p;
        }
        else
        {
            q.head = q.head->next;
            delete p;
        }
        return val;
    }
    return 0;
}
bool isEmptyQ(Queue &q)
{
    if (q.head == 0 && q.tail == 0)
        return true;
    return false;
}


void initSChar(StivaChar *&s){
    s=0;
}
void pushChar(StivaChar*&s, char val){
    StivaChar *p = new StivaChar;
    p->data = val;
    p->next = s;
    s = p;
}
char popChar(StivaChar*&s){
    if (!isEmptySChar(s))
    {
        StivaChar *p;
        p = s;
        char val = p->data;
        s = s->next;
        delete p;
        return val;
    }
    return 0;
}
bool isEmptySChar(StivaChar*s){
    if(s==0)
        return true;
    return false;
}

//ex 6

bool palindromStiva(char c[]){
    StivaChar*s;
    initSChar(s);
    for(int i=0; i<strlen(c); i++)
    {
        pushChar(s,c[i]);
    }

    for(int i=strlen(c)-1;i>0;i--)
    {
        if(c[i]!=popChar(s))
            return false;
    }
    return true;

}

//ex 10
bool palindrom(int v[], int n)
{
    Stiva *s;
    Queue q;
    initS(s);
    initQ(q);

    for(int i=0;i<n;i++){
        push(s,v[i]);
        put(q,v[i]);
    }
    while(!isEmptyQ(q) && !isEmptyS(s)){
        if(pop(s)!=get(q))
            return false;
    }
    return true;
}

//ex 8

void pushMax(Stiva*&s, int val){
    Stiva *p=new Stiva;
    p->data=val;
    p->next=s;
    s=p;
    if((s->next!=0)&&(s->data<s->next->data))
        swap(s->data, s->next->data);
}

//ex 1

void inserare(Lista*&cap, int val){
    Lista*p=new Lista;
    p->data=val;
    p->next=cap;
    cap=p;
}

void afisareLista(Lista*cap){
    while(cap){
        cout<<cap->data<<" ";
        cap=cap->next;
    }
}

//ex 1
void listaMaxim(Lista*&cap){
    Lista*p=cap,*maxi=cap;
    while(p!=NULL){
        if(p->data>maxi->data) 
            maxi=p;
        if(p->next==0) //ultima pozitie
            swap(p->data,maxi->data);
        p=p->next;
    }
}

//ex 2
void listaMinim(Lista*&cap){
    Lista*p=cap,*maxi=cap;
    while(p!=NULL){
        if(p->data<maxi->data) 
            maxi=p;
        p=p->next;
    } 
    swap(cap->data,maxi->data);
}