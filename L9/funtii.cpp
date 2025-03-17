#include <iostream>
#include "header.h"
using namespace std;

void insert(Nod*&r, int val){
    if(r==NULL)
        {
            r=make_nod(val);
            return;
        }
    if(val<r->data)
        insert(r->stg,val);
    else if(val>r->data)
            insert(r->drt,val);

}
void insert_nerecursiv(Nod*&r, int val){
    if(r==0)
        r=make_nod(val);
    else{
        Nod*p=r;
        Nod*p1;
        while(p!=NULL){
            p1=p;
            if(val<p->data)
                p=p->stg;
            else if(val>p->data)
                p=p->drt;
        }
        if(val<p1->data)
            p1->stg=make_nod(val);
        else 
            p1->drt=make_nod(val);
    }
}
Nod*make_nod(int val){
    Nod*p=new Nod;
    p->data=val;
    p->stg=0;
    p->drt=0;
    return p;
}
void inordine(Nod *r){
    if(r!=NULL){
        inordine(r->stg);
        cout<<r->data<<" ";
        inordine(r->drt);
    }
}

int search(Nod*r, int val){
    if(r==0)
        return 0;
    if(val==r->data)
            return 1;
    if(val<r->data)
        return search(r->stg,val);
    else 
        return search(r->drt,val);
}

int minim(Nod*r){
    if(r==0)
        return 0;
    if(r->stg==NULL)
        return r->data;
    else 
        return minim(r->stg);
}

int maxim(Nod*r){
    if(r==0)
        return 0;
    if(r->drt==0)
        return r->data;
    else 
        return maxim(r->drt);
}

void Delete(Nod*&r,int val){
    if(r==0)
        return;
    if(val<r->data)
        Delete(r->stg,val);
    else 
        if(val>r->data)
            Delete(r->drt,val);
            else 
                DeleteRoot(r);
}
void DeleteRoot(Nod*&r){
    Nod*p=r;
    if(r->stg==0) //daca r are fiu drept sau este frunza
    {
        r=r->drt;
        delete p;
    }
    else if(r->drt==0)//daca r are fiu stang sau este frunza
    {
        r=r->stg;
        delete p;
    }
    else {
        r=removeGreatest(r->stg);//are 2 fii
        r->stg=p->stg;
        r->drt=p->drt;
        delete p;
    }
}
Nod*removeGreatest(Nod*&r){
    Nod*p;
    if(r->drt==0){
        p=r;
        r=r->stg;
        return p;
    }
    else 
        return removeGreatest(r->drt);
}

void afisare_indentat(Nod*r, int nivel){
    int i;
    for(int i=0;i<nivel;i++)
    {
        cout<<"\t";
        if(r==0) 
            cout<<"-"<<"\n";
        else{
            cout<<r->data<<endl;
            afisare_indentat(r->stg,nivel+1);
            afisare_indentat(r->drt,nivel+1);
        }
    }
}