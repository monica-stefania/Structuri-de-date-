#include <iostream>
#include<string.h>
#include "header.h"

using namespace std;

void inserare(Persoana *&cap, char *n, char *t){
    Persoana*p=new Persoana;
    p->nume=new char[strlen(n)];
    p->tel=new char[strlen(t)];
    strcpy(p->nume,n);
    strcpy(p->tel,t);
    p->next=cap;
    cap=p;
}
void afisare(Persoana *cap){
    while(cap){
        cout<<cap->nume<<" "<<cap->tel<<" ";
        cap=cap->next;
    }
    cout<<"\n";
}