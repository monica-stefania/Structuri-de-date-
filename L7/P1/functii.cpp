#include <iostream>
#include <fstream>
#include "header.h"
#include <string.h>
using namespace std;

void initializare(Nod*HT[]){
    for(int i=0;i<M;i++)
        HT[i]=0;
}
int f(char *key){
    int suma=0;
    for(int i=0;i<strlen(key);i++)
        suma=suma+*(key+i);
    return suma%M;
}
void inserare(Nod*HT[],char *key){
    Nod*p=new Nod;
    int index;
    index=f(key);
    p->cheie=new char[strlen(key)+1];
    strcpy(p->cheie,key);
    if(HT[index]==0){
        HT[index]=p;
        p->next=0;
    }
    else{
        Nod *q;
        q=find(HT,key);
        if(q==0){
            p->next=HT[index];
            HT[index]=p;
        }
        else
            cout<<"\nCheia deja exista";
    }
}
Nod*find(Nod*HT[],char*key){
    int index;
    index=f(key);
    Nod*p;
    p=HT[index];
    while(p!=0){
        if(strcmp(key,p->cheie)==0)
            return p;
        p=p->next;
    }
    return 0;
}
void afisare(Nod*HT[]){
    for(int i=0;i<M;i++){
        if(HT[i]!=0){
            cout<<"Inregistrarile avand codul de dispersie: "<<i<<"\n";
            Nod*p=HT[i];
            while(p){
                cout<<p->cheie<<" ";
                p=p->next;
            }
        }
        cout<<"\n";
    }
}