#include <iostream>
#include "header.h"
using namespace std;
void inserare(Nod *&cap, int val)
{
    Nod *p = new Nod;
    p->data = val;
    if (cap == 0)
    {
        p->next = p;
        cap = p;
    }
    else
    {
        p->next = cap->next;
        cap->next = p;
        cap = p;
    }
}
void afisare(Nod *cap)
{
    Nod*p=cap;
    while(p->next!=cap){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<p->data<<" ";
}
void permutari(Nod *cap){
    Nod *p = cap;
    while(p->next!=cap){
        afisare(p);
        cout<<"\n";
        p=p->next;
    }
    afisare(p);
}

void inversare(Nod*&cap){
    Nod*p=cap;
    Nod*pred=0;
    Nod*urm=0;
    while(p->next!=cap)
    {
        urm=p->next;
        p->next=pred;
        pred=p;
        p=urm;
    }
    p->next=pred;
    cap->next=p;
    cap=p;
}