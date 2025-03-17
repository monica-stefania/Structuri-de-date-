#include <iostream>
#include "header.h"
using namespace std;

void inserare(Nod*&cap, int val){
    Nod*p=new Nod;
    p->data=val;
    p->pred=0;
    if(cap==NULL){
        p->succ=0;
        cap=p;
    }
    else{
        p->succ=cap;
        cap->pred=p;
        cap=p;
    }

}
void afisare(Nod*cap){
    while(cap){
        cout<<cap->data<<" ";
        cap=cap->succ;
    }
}
void inserarepoz(Nod*&cap, int val, int poz){
    Nod*p=new Nod;
    Nod*q=cap;
    int k=1;
    p->data=val;
    if(poz==1)
        inserare(cap,val);
    else 
        {
        while(q!=NULL && poz-2!=k){
                q=q->succ;
                k++;
        }
        p->succ=q->succ;
        q->succ->pred=p;
        p->pred=q;
        q->succ=p; 
        }
}

void stergere(Nod*&cap,int poz){
    Nod*q=cap;
    int k=1;
    if(poz==1){
        cap=cap->succ;
        cap->pred=0;
        delete q;
    }
    else{
        while(q!=0 && poz-1!=k){
            q=q->succ;
            k++;
        }
        q->pred->succ=q->succ;
        q->succ->pred=q->pred;
    }

}