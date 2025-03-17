#include <iostream>
#include "header.h"
using namespace std;

bool EqRequired;

void inserare(Nod*&r, int val){
    if(r==0){
        r=make_nod(val);
        EqRequired=true;
    }
    else 
        if(val<r->data){
            inserare(r->stg, val);
            echilibrare(r,val,true);
        }
        else if(val>r->data){
            inserare(r->drt, val);
            echilibrare(r,val,false);
        }
}
void echilibrare(Nod*&r, int val, bool k){
    if(EqRequired){
        if(k==true) //inserarea s-a efectuat in partea stanga
        {
            switch(r->bf){
                case 1: //adancimea pe SAS este mai mare
                        EqRequired=false;//resetare flag
                        if(val<r->stg->data) //aleg tipul de rotatie
                            RSD(r);
                        else 
                            RDD(r);
                        break;
                case 0: //nu exista dezechilibru inainte de inserare
                        r->bf=1; //se produce acum, creste adacimea pe stanga 
                        break;
                case -1: //adancimea pe SAD este mai mare
                        r->bf=0;//inserarea produce echilibru pt nodul critic
                        EqRequired=false;
                        break;

            }
        }
        else //inserarea s-a facut la dreapta
        {
            switch(r->bf){
                case 1: //adancimea pe SAS este mai mare 
                    r->bf=0; //inserarea produce echilibru 
                    EqRequired=false;
                    break;
                case 0: //nu exista dezechilibru inainte de inserare
                        r->bf=-1; //inserarea s-a efectuat in dreapta: h(SAS)-h(SAD)=-1, crestea adancimea in dreapta
                        break;
                case -1: //adancimea pe SAD este mai mare
                        EqRequired=false;
                        if(val>r->drt->data)
                            RSS(r);
                        else 
                            RDS(r);
                        break;

            }
        }
    }

}

Nod*make_nod(int val){
    Nod*r=new Nod;
    r->data=val;
    r->stg=0;
    r->drt=0;
    r->bf=0;
    return r;
}

void RSD(Nod*&a){
    cout<<"RSD("<<a->data<<")\n";
    Nod*b;
    b=a->stg;
    a->stg=b->drt;
    b->drt=a;
    a->bf=0;
    b->bf=0;
    a=b;
}
void RSS(Nod*&a){
    cout<<"RSS("<<a->data<<")\n";
    Nod*b;
    b=a->drt;
    a->drt=b->stg;
    b->stg=a;
    a->bf=0;
    b->bf=0;
    a=b;
}
void RDD(Nod*&a){
    cout<<"RDD("<<a->data<<")\n";
    Nod*b,*c;
    b=a->stg;
    c=b->drt;
    //se actualizeaza bf pentru starea finala
    switch(c->bf){
        case 0: //h(t2s)=h(t2d)  inainte de refacea legaturilor 
                a->bf=b->bf=0; //inserarea echilibreaza
                break;
        case -1: //h(t2s)<h(t2d) inainte de refacea legaturilor
                a->bf=0; //h(T3)=h(t2d)
                b->bf=1; //h(T1)>h(t2s)
                break;
        case 1: //h(2ts)>h(t2d) inainte de refacea legaturilor 
                a->bf=-1;//h(t2d)<h(T3)
                b->bf= 0;//h(T1)=h(t2s)
    }
    b->drt=c->stg;
    c->stg=b;
    a->stg=c->drt;
    c->drt=a;
    c->bf=0;
    a=c;
}
void RDS(Nod*&a){
    cout<<"RDS("<<a->data<<")\n";
    Nod*b,*c;
    b=a->drt;
    c=b->stg;
    switch(c->bf){
        case 0: //h(t2s)=h(t2d) inainte de refacerea legaturilor 
                a->bf=b->bf=0;
                break;
        case 1: //h(t2s)>h(t2d)
                a->bf=0; //h(T1)=h(t2s)
                b->bf=-1; //h(t2d)<h(T3)
                break;
        case -1: //h(t2s)<h(t2d)
                a->bf=1;//h(T1)>h(tss)
                b->bf=0; //h(t2d)=h(T3)
                break;
    }
    b->stg=c->drt;
    c->drt=b;
    a->drt=c->stg;
    c->stg=a;
    c->bf=0;
    a=c;
}

void inordine(Nod*r){
    if(r){
        inordine(r->stg);
        cout<<r->data<<" ";
        inordine(r->drt);
    }
}