#include <iostream>
#include "header.h"

using namespace std;

void Inserare(Nod*&cap,int val){
    Nod*p=new Nod;
    p->data=val;
    p->succ=cap;
    cap=p;

}
void Afisare(Nod*cap){
    while (cap)
    {
        cout<<cap->data;
        cout<<" ";
        cap=cap->succ;
    }
}
int Cautare(Nod*cap, int val){
    while(cap!=NULL)
        {
            if(cap->data==val)
                return 1;
            cap=cap->succ;
        }
    return 0;
}
void InserarePoz(Nod*&cap, int val, int poz)
{
    Nod*p=new Nod;
    Nod*q=new Nod;
    int k=1;
    q=cap;
    if(poz==1)
        Inserare(cap,val);
    else
        {
            while(q!=NULL && k!=poz-1)
                {
                    q=q->succ;
                    k++;
                }
            p->data=val;
            p->succ=q->succ;
            q->succ=p;
        }

}
void StergerePoz(Nod*&cap, int poz){
    Nod*p=new Nod;
    Nod*q=new Nod;
    int k=1;
    q=cap;
    if(poz==1){
        cap=q->succ;
        delete q;
    }
    else
        {
            while(q!=NULL && k!=poz-1)
                {
                    q=q->succ;
                    k++;
                }
            p=q->succ;
            q->succ=p->succ;
            delete p;
        }

}
void parcurgere(Nod*cap){
    Nod*p=new Nod;
    Nod*q=new Nod;
    Nod*pred=new Nod;
    pred=NULL;
    p=cap;
    q=cap;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->succ;
    }
    cout<<endl;
    while(q!=0)
    {
        Nod*urm=q->succ;
        q->succ=pred;
        pred=q;
        q=urm;
    }
    q=pred;
    while(q)
    {
        cout<<q->data<<" ";
        q=q->succ;
    }
}
void mijloc(Nod*cap){
    Nod*p=new Nod;
    Nod*q=new Nod;
    p=cap;
    q=cap;
    while(q!=0 && q->succ!=0)
    {
        p=p->succ;
        q=q->succ->succ;
        //cout<<p->data<<endl;
    }
   cout<<p->data<<endl;
}
Nod*inversare(Nod*cap){
    Nod*p=0,*q=0,*r=0;
    p=cap;
    q=p->succ;
    r=q->succ;
    p->succ=0;
    while(r->succ!=0)
    {
        q->succ=p;
        p=q;
        q=r;
        r=r->succ;
    }
    q->succ=p;
    r->succ=q;
    return r;
}
void AfisarePoz(Nod*cap, int poz){
    Nod*p=new Nod;
    p=cap;
    //p=inversare(cap);
    int k=1;
    while(p!=NULL && k!=poz)
        {
            k++;
            p=p->succ;
        }
    cout<<p->data<<endl;
}

void concatenare(Nod*&cap, Nod*x,Nod*y){
    while(x)
    {
        Inserare(cap,x->data);
        x=x->succ;
    }
    while(y){
        Inserare(cap,y->data);
        y=y->succ;
    }
}